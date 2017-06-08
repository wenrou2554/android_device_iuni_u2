/*
 * Copyright (C) 2015 The CyanogenMod Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_HARDWARE_CAMERA_PARAMETERS_EXT_H
#define ANDROID_HARDWARE_CAMERA_PARAMETERS_EXT_H

#include <utils/KeyedVector.h>

namespace android {

class CameraParameters;
struct Size;

class GNCameraParameters
{
public:
    GNCameraParameters();
    GNCameraParameters(CameraParameters *p);
    ~GNCameraParameters();

    int get_from_attr(const char *path, char *buf, size_t len);
    bool check_flashlight_restriction();
    int lookupAttr(/* GNCameraParameters::CameraMap const* */
            void *cameraMap, int a3, const char *a4);

    const char *getPreviewFrameRateMode() const;
    void setPreviewFrameRateMode(const char *mode);
	void setPictureFrame(const char *mode);
	void setDefaultParameters(const char *);

    void setBrightnessLumaTargetSet(int brightness, int luma);
    int getBrightnessLumaTargetSet(int *brightness, int *luma) const;

    void setTouchIndexAec(int x, int y);
    void getTouchIndexAec(int *x, int *y);

    void setTouchIndexAf(int x, int y);
    void getTouchIndexAf(int *x, int *y);

    void setZsl(const char *mode);
    const char *getZsl() const;

    void setRawSize(int x, int y);
    void getRawSize(int *x, int *y);

    void getMeteringAreaCenter(int *x, int *y) const;
    void getSupportedHfrSizes(Vector<Size> &sizes) const;
    void setPreviewFpsRange(int min, int max);
    int getOrientation() const;
    void setOrientation(int orientation);

    static const char KEY_PICTURE_FRAME[];
    static const char PICTURE_FRAME_NORMAL[];
    static const char KEY_GESTURE_MODE[];
    static const char GESTURE_MODE_ON[];
    static const char KEY_GESTURE_EVENT_TYPE[];
    static const char GESTURE_EVENT_OPEN_HAND_PRESENCE[];
    static const char GESTURE_EVENT_FACE_PRESENCE[];
    static const char GESTURE_EVENT_FIST_PRESENCE[];
    static const char KEY_MIRROR_MODE[];
    static const char MIRROR_MODE_ON[];
    static const char KEY_SCENE_DETECTION_MODE[];
    static const char SCENE_DETECTION_ON[];
    static const char KEY_CAPTURE_MODE[];
    static const char CAPTURE_MODE_NIGHTSHOT_SHOT[];
    static const char KEY_FACE_BEAUTY_MODE[];
    static const char FACE_BEAUTY_ON[];
    static const char KEY_FACE_BEAUTY_LEVEL[];
    static const char CAPTURE_MODE_NORMAL[];
    static const char SCENE_DETECTION_OFF[];
    static const char GESTURE_EVENT_NONE[];
    static const char MIRROR_MODE_OFF[];
    static const char FACE_BEAUTY_OFF[];
    static const char GESTURE_MODE_OFF[];
    static const char CAPTURE_MODE_BURST_SHOT[];
    static const char KEY_CONTIBURST_SUPPORTED_MODE[];
    static const char KEY_NON_ZSL_MANUAL_MODE[];
    static const char KEY_VIDEO_MODE[];
    static const char KEY_FORCE_USE_AUDIO_ENABLED[];
    static const char KEY_SLOW_MOTION_VERSION[];
    static const char KEY_SAVE_MIRROR[];
    static const char DENOISE_ON[];
    static const char DENOISE_OFF[];

private:
    CameraParameters *mParams;
};

}

#endif


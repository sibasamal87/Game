LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := game_shared

LOCAL_MODULE_FILENAME := libgame

FILE_LIST := $(wildcard $(LOCAL_PATH)/hellocpp/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/game/LWGame/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/game/LWPublic/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/game/*.cpp)

LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)
                   
LOCAL_C_INCLUDES := $(LOCAL_PATH)/game  
LOCAL_C_INCLUDES += $(LOCAL_PATH)/game/LWGame  
LOCAL_C_INCLUDES += $(LOCAL_PATH)/game/LWPublic 

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static cocos_extension_static
            
include $(BUILD_SHARED_LIBRARY)

$(call import-module,CocosDenshion/android) \
$(call import-module,cocos2dx) \
$(call import-module,extensions)

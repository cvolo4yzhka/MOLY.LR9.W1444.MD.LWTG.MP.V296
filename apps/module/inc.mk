CURRENT_LOCAL_PATH := $(LOCAL_PATH)

MODULE_DIR:= $(MTK_BUILD_ROOT)/module

MOD_MAL_DIR:= $(MODULE_DIR)/mal
MOD_VOLTE_DIR:= $(MODULE_DIR)/volte
MOD_DUMMY_DIR:= $(MODULE_DIR)/dummy
MOD_EPDG_DIR:= $(MODULE_DIR)/epdg
MOD_VERNO_DIR:= $(MODULE_DIR)/verno
MOD_STRONGSWAN_DIR:= $(MODULE_DIR)/strongswan


MTK_EXECUTABLE     := $(BUILD_EXECUTABLE)
MTK_STATIC_LIBRARY := $(BUILD_STATIC_LIBRARY)
MTK_SHARED_LIBRARY := $(BUILD_SHARED_LIBRARY)

MTK_INTERNAL     := yes
USE_VOLTE_NDK    := yes
USE_MTK_NDK_BUILD := yes

EXTERNAL_LDLIBS   += -ldl
EXTERNAL_LDLIBS     += -llog
EXTERNAL_LDFLAGS += -nodefaultlibs -stdlib=libc++
EXTERNAL_CFLAGS  += -nodefaultlibs -stdlib=libc++

ifeq ($(MTK_DEBUG),1)
    TARGET_BUILD_VARIANT := eng
else
    TARGET_BUILD_VARIANT := user
endif



ifneq ($(findstring android,$(APP_PLATFORM)),)
-include $(MOD_DUMMY_DIR)/app.mk
endif

EXTERNAL_SHARED_LIBRARIES += libverno
ifneq ($(wildcard $(MOD_VERNO_DIR)/app.mk),)
    include $(MOD_VERNO_DIR)/app.mk
else
    include $(MOD_VERNO_DIR)/pre_build.mk
endif


LOCAL_PATH := $(CURRENT_LOCAL_PATH)

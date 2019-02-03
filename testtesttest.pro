QT += gui quick

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    src \
    proto/cpp \
    src/protobuf/include \
    src/zlib/include \
    src/Eigen

    CONFIG(release,debug|release){
        PROTOBUF_LIB = $$PWD/src/protobuf/lib/libprotobuf.lib
        ZLIB_LIB = $$PWD/src/zlib/lib/zlib.lib
    }
    CONFIG(debug,debug|release){
        PROTOBUF_LIB = $$PWD/src/protobuf/lib/libprotobufD.lib
        ZLIB_LIB = $$PWD/src/zlib/lib/zlibD.lib
    }

LIBS += $$PROTOBUF_LIB \
        $$ZLIB_LIB

SOURCES += main.cpp \
    netreceive/netreceive.cpp \
    convert/chipsolver.cpp \
    convert/collisiondetect.cpp \
    convert/dealball.cpp \
    convert/dealrobot.cpp \
    convert/kalmanfilter.cpp \
    convert/kalmanfilterdir.cpp \
    convert/maintain.cpp \
    convert/montage.cpp \
    convert/visionmodule.cpp \
    logreader/file_format_legacy.cpp \
    logreader/file_format_timestamp_type_size_raw_message.cpp \
    logreader/log_file.cpp \
    logreader/log_slider.cpp \
    logreader/player.cpp \
    logreader/qtiocompressor.cpp \
    logreader/timer.cpp \
    logwriter/logwriter.cpp \
    netsend/netsend.cpp \
    src/geometry.cpp \
    src/globaldata.cpp \
    src/globalsettings.cpp \
    src/matrix2d.cpp \
    src/singleparams.cpp \
    src/treeitem.cpp \
    proto/cpp/game_event.pb.cc \
    proto/cpp/grSim_Commands.pb.cc \
    proto/cpp/grSim_Packet.pb.cc \
    proto/cpp/grSim_Replacement.pb.cc \
    proto/cpp/grSimMessage.pb.cc \
    proto/cpp/messages_robocup_ssl_detection.pb.cc \
    proto/cpp/messages_robocup_ssl_geometry.pb.cc \
    proto/cpp/messages_robocup_ssl_geometry_legacy.pb.cc \
    proto/cpp/messages_robocup_ssl_refbox_log.pb.cc \
    proto/cpp/messages_robocup_ssl_wrapper.pb.cc \
    proto/cpp/messages_robocup_ssl_wrapper_legacy.pb.cc \
    proto/cpp/referee.pb.cc \
    proto/cpp/vision_detection.pb.cc \
    proto/cpp/zss_cmd.pb.cc \
    proto/cpp/zss_debug.pb.cc \
    proto/cpp/zss_train.pb.cc \
    src/parammanager.cpp

HEADERS += \
    netreceive/netreceive.h \
    convert/ballrecords.h \
    convert/chipsolver.h \
    convert/collisiondetect.h \
    convert/dealball.h \
    convert/dealrobot.h \
    convert/kalmanfilter.h \
    convert/kalmanfilterdir.h \
    convert/maintain.h \
    convert/messageformat.h \
    convert/montage.h \
    convert/visionmodule.h \
    logreader/file_format.h \
    logreader/file_format_legacy.h \
    logreader/file_format_timestamp_type_size_raw_message.h \
    logreader/log_file.h \
    logreader/log_slider.h \
    logreader/message_type.h \
    logreader/player.h \
    logreader/qtiocompressor.h \
    logreader/timer.h \
    logwriter/logwriter.h \
    netsend/netsend.h \
    src/dataqueue.hpp \
    src/geometry.h \
    src/globaldata.h \
    src/globalsettings.h \
    src/json.hpp \
    src/matrix2d.h \
    src/singleparams.h \
    src/singleton.hpp \
    src/staticparams.h \
    src/treeitem.h \
    proto/cpp/game_event.pb.h \
    proto/cpp/grSim_Commands.pb.h \
    proto/cpp/grSim_Packet.pb.h \
    proto/cpp/grSim_Replacement.pb.h \
    proto/cpp/grSimMessage.pb.h \
    proto/cpp/messages_robocup_ssl_detection.pb.h \
    proto/cpp/messages_robocup_ssl_geometry.pb.h \
    proto/cpp/messages_robocup_ssl_geometry_legacy.pb.h \
    proto/cpp/messages_robocup_ssl_refbox_log.pb.h \
    proto/cpp/messages_robocup_ssl_wrapper.pb.h \
    proto/cpp/messages_robocup_ssl_wrapper_legacy.pb.h \
    proto/cpp/referee.pb.h \
    proto/cpp/vision_detection.pb.h \
    proto/cpp/zss_cmd.pb.h \
    proto/cpp/zss_debug.pb.h \
    proto/cpp/zss_train.pb.h \
    src/parammanager.h

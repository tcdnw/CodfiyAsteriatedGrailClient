######################################################################
# Automatically generated by qmake (3.0) ?? ?? 20 23:19:24 2014
######################################################################

TEMPLATE = app
TARGET = gui
INCLUDEPATH += . widget data client logic
QT += network widgets multimedia
INCLUDEPATH += include
LIBS += lib/libprotobuf.lib

# Input
HEADERS += client/Client.h \
           client/ClientUI.h \
           client/codec.h \
           client/Lobby.h \
           client/RoomSet.h \
           data/Card.h \
           data/Common.h \
           data/DataInterface.h \
           data/Player.h \
           data/SafeList.h \
           data/Team.h \
           logic/AnSha.h \
           logic/DieWu.h \
           logic/FengYin.h \
           logic/GeDouJia.h \
           logic/GongNv.h \
           logic/HongLian.h \
           logic/JianDi.h \
           logic/JianSheng.h \
           logic/KuangZhan.h \
           logic/Lingfu.h \
           logic/LingHun.h \
           logic/Logic.h \
           logic/MaoXian.h \
           logic/MoDao.h \
           logic/MoGong.h \
           logic/MoJian.h \
           logic/MoNv.h \
           logic/MoQiang.h \
           logic/NvWuShen.h \
           logic/QiDao.h \
           logic/Role.h \
           logic/ShengNv.h \
           logic/ShengQiang.h \
           logic/ShenGuan.h \
           logic/ShiRen.h \
           logic/SiLing.h \
           logic/TianShi.h \
           logic/WuNv.h \
           logic/XianZhe.h \
           logic/YingLingRenXing.h \
           logic/YongZhe.h \
           logic/YuanSu.h \
           logic/ZhongCai.h \
           protocol/action_respond.pb.h \
           protocol/base.pb.h \
           protocol/GameMessage.pb.h \
           widget/Animation.h \
           widget/BPArea.h \
           widget/Button.h \
           widget/ButtonArea.h \
           widget/CardItem.h \
           widget/GUI.h \
           widget/HandArea.h \
           widget/LogArea.h \
           widget/PlayerArea.h \
           widget/PlayerItem.h \
           widget/RoleItem.h \
           widget/RoomScene.h \
           widget/RoomView.h \
           widget/ShowArea.h \
           widget/TeamArea.h \
           widget/TipArea.h \
           include/google/protobuf/descriptor.h \
           include/google/protobuf/descriptor.pb.h \
           include/google/protobuf/descriptor_database.h \
           include/google/protobuf/dynamic_message.h \
           include/google/protobuf/extension_set.h \
           include/google/protobuf/generated_enum_reflection.h \
           include/google/protobuf/generated_message_reflection.h \
           include/google/protobuf/generated_message_util.h \
           include/google/protobuf/message.h \
           include/google/protobuf/message_lite.h \
           include/google/protobuf/reflection_ops.h \
           include/google/protobuf/repeated_field.h \
           include/google/protobuf/service.h \
           include/google/protobuf/text_format.h \
           include/google/protobuf/unknown_field_set.h \
           include/google/protobuf/wire_format.h \
           include/google/protobuf/wire_format_lite.h \
           include/google/protobuf/wire_format_lite_inl.h \
           include/google/protobuf/compiler/code_generator.h \
           include/google/protobuf/compiler/command_line_interface.h \
           include/google/protobuf/compiler/importer.h \
           include/google/protobuf/compiler/parser.h \
           include/google/protobuf/compiler/plugin.h \
           include/google/protobuf/io/coded_stream.h \
           include/google/protobuf/io/gzip_stream.h \
           include/google/protobuf/io/printer.h \
           include/google/protobuf/io/tokenizer.h \
           include/google/protobuf/io/zero_copy_stream.h \
           include/google/protobuf/io/zero_copy_stream_impl.h \
           include/google/protobuf/io/zero_copy_stream_impl_lite.h \
           include/google/protobuf/stubs/atomicops.h \
           include/google/protobuf/stubs/atomicops_internals_x86_msvc.h \
           include/google/protobuf/stubs/common.h \
           include/google/protobuf/stubs/once.h \
           include/google/protobuf/stubs/platform_macros.h \
           include/google/protobuf/stubs/template_util.h \
           include/google/protobuf/stubs/type_traits.h \
           include/google/protobuf/compiler/cpp/cpp_generator.h \
           include/google/protobuf/compiler/java/java_generator.h \
           include/google/protobuf/compiler/python/python_generator.h \
    widget/Timelinebar.h
FORMS += client/ClientUI.ui client/Lobby.ui client/RoomSet.ui
SOURCES += main.cpp \
           client/Client.cpp \
           client/ClientUI.cpp \
           client/codec.cpp \
           client/Lobby.cpp \
           client/RoomSet.cpp \
           data/Card.cpp \
           data/DataInterface.cpp \
           data/Player.cpp \
           data/Team.cpp \
           data/Common.cpp \
           logic/AnSha.cpp \
           logic/DieWu.cpp \
           logic/FengYin.cpp \
           logic/GeDouJia.cpp \
           logic/GongNv.cpp \
           logic/HongLian.cpp \
           logic/JianDi.cpp \
           logic/JianSheng.cpp \
           logic/KuangZhan.cpp \
           logic/Lingfu.cpp \
           logic/LingHun.cpp \
           logic/Logic.cpp \
           logic/MaoXian.cpp \
           logic/MoDao.cpp \
           logic/MoGong.cpp \
           logic/MoJian.cpp \
           logic/MoNv.cpp \
           logic/MoQiang.cpp \
           logic/NvWuShen.cpp \
           logic/QiDao.cpp \
           logic/Role.cpp \
           logic/ShengNv.cpp \
           logic/ShengQiang.cpp \
           logic/ShenGuan.cpp \
           logic/ShiRen.cpp \
           logic/SiLing.cpp \
           logic/TianShi.cpp \
           logic/WuNv.cpp \
           logic/XianZhe.cpp \
           logic/YingLingRenXing.cpp \
           logic/YongZhe.cpp \
           logic/YuanSu.cpp \
           logic/ZhongCai.cpp \
           protocol/action_respond.pb.cc \
           protocol/base.pb.cc \
           protocol/GameMessage.pb.cc \
           widget/Animation.cpp \
           widget/BPArea.cpp \
           widget/Button.cpp \
           widget/ButtonArea.cpp \
           widget/CardItem.cpp \
           widget/GUI.cpp \
           widget/HandArea.cpp \
           widget/LogArea.cpp \
           widget/PlayerArea.cpp \
           widget/PlayerItem.cpp \
           widget/RoleItem.cpp \
           widget/RoomScene.cpp \
           widget/RoomView.cpp \
           widget/ShowArea.cpp \
           widget/TeamArea.cpp \
           widget/TipArea.cpp \
           widget/Timelinebar.cpp \


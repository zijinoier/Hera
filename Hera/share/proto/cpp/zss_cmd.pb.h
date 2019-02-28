// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: zss_cmd.proto

#ifndef PROTOBUF_zss_5fcmd_2eproto__INCLUDED
#define PROTOBUF_zss_5fcmd_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace ZSS {
namespace Protocol {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_zss_5fcmd_2eproto();
void protobuf_AssignDesc_zss_5fcmd_2eproto();
void protobuf_ShutdownFile_zss_5fcmd_2eproto();

class Robots_Status;
class Robot_Status;
class Robots_Command;
class Robot_Command;

// ===================================================================

class Robots_Status : public ::google::protobuf::Message {
 public:
  Robots_Status();
  virtual ~Robots_Status();

  Robots_Status(const Robots_Status& from);

  inline Robots_Status& operator=(const Robots_Status& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Robots_Status& default_instance();

  void Swap(Robots_Status* other);

  // implements Message ----------------------------------------------

  Robots_Status* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Robots_Status& from);
  void MergeFrom(const Robots_Status& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .ZSS.Protocol.Robot_Status robots_status = 1;
  inline int robots_status_size() const;
  inline void clear_robots_status();
  static const int kRobotsStatusFieldNumber = 1;
  inline const ::ZSS::Protocol::Robot_Status& robots_status(int index) const;
  inline ::ZSS::Protocol::Robot_Status* mutable_robots_status(int index);
  inline ::ZSS::Protocol::Robot_Status* add_robots_status();
  inline const ::google::protobuf::RepeatedPtrField< ::ZSS::Protocol::Robot_Status >&
      robots_status() const;
  inline ::google::protobuf::RepeatedPtrField< ::ZSS::Protocol::Robot_Status >*
      mutable_robots_status();

  // @@protoc_insertion_point(class_scope:ZSS.Protocol.Robots_Status)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::ZSS::Protocol::Robot_Status > robots_status_;
  friend void  protobuf_AddDesc_zss_5fcmd_2eproto();
  friend void protobuf_AssignDesc_zss_5fcmd_2eproto();
  friend void protobuf_ShutdownFile_zss_5fcmd_2eproto();

  void InitAsDefaultInstance();
  static Robots_Status* default_instance_;
};
// -------------------------------------------------------------------

class Robot_Status : public ::google::protobuf::Message {
 public:
  Robot_Status();
  virtual ~Robot_Status();

  Robot_Status(const Robot_Status& from);

  inline Robot_Status& operator=(const Robot_Status& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Robot_Status& default_instance();

  void Swap(Robot_Status* other);

  // implements Message ----------------------------------------------

  Robot_Status* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Robot_Status& from);
  void MergeFrom(const Robot_Status& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 robot_id = 1;
  inline bool has_robot_id() const;
  inline void clear_robot_id();
  static const int kRobotIdFieldNumber = 1;
  inline ::google::protobuf::int32 robot_id() const;
  inline void set_robot_id(::google::protobuf::int32 value);

  // required bool infrared = 2;
  inline bool has_infrared() const;
  inline void clear_infrared();
  static const int kInfraredFieldNumber = 2;
  inline bool infrared() const;
  inline void set_infrared(bool value);

  // required bool flat_kick = 3;
  inline bool has_flat_kick() const;
  inline void clear_flat_kick();
  static const int kFlatKickFieldNumber = 3;
  inline bool flat_kick() const;
  inline void set_flat_kick(bool value);

  // required bool chip_kick = 4;
  inline bool has_chip_kick() const;
  inline void clear_chip_kick();
  static const int kChipKickFieldNumber = 4;
  inline bool chip_kick() const;
  inline void set_chip_kick(bool value);

  // @@protoc_insertion_point(class_scope:ZSS.Protocol.Robot_Status)
 private:
  inline void set_has_robot_id();
  inline void clear_has_robot_id();
  inline void set_has_infrared();
  inline void clear_has_infrared();
  inline void set_has_flat_kick();
  inline void clear_has_flat_kick();
  inline void set_has_chip_kick();
  inline void clear_has_chip_kick();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int32 robot_id_;
  bool infrared_;
  bool flat_kick_;
  bool chip_kick_;
  friend void  protobuf_AddDesc_zss_5fcmd_2eproto();
  friend void protobuf_AssignDesc_zss_5fcmd_2eproto();
  friend void protobuf_ShutdownFile_zss_5fcmd_2eproto();

  void InitAsDefaultInstance();
  static Robot_Status* default_instance_;
};
// -------------------------------------------------------------------

class Robots_Command : public ::google::protobuf::Message {
 public:
  Robots_Command();
  virtual ~Robots_Command();

  Robots_Command(const Robots_Command& from);

  inline Robots_Command& operator=(const Robots_Command& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Robots_Command& default_instance();

  void Swap(Robots_Command* other);

  // implements Message ----------------------------------------------

  Robots_Command* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Robots_Command& from);
  void MergeFrom(const Robots_Command& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .ZSS.Protocol.Robot_Command command = 1;
  inline int command_size() const;
  inline void clear_command();
  static const int kCommandFieldNumber = 1;
  inline const ::ZSS::Protocol::Robot_Command& command(int index) const;
  inline ::ZSS::Protocol::Robot_Command* mutable_command(int index);
  inline ::ZSS::Protocol::Robot_Command* add_command();
  inline const ::google::protobuf::RepeatedPtrField< ::ZSS::Protocol::Robot_Command >&
      command() const;
  inline ::google::protobuf::RepeatedPtrField< ::ZSS::Protocol::Robot_Command >*
      mutable_command();

  // optional int32 delay = 2;
  inline bool has_delay() const;
  inline void clear_delay();
  static const int kDelayFieldNumber = 2;
  inline ::google::protobuf::int32 delay() const;
  inline void set_delay(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:ZSS.Protocol.Robots_Command)
 private:
  inline void set_has_delay();
  inline void clear_has_delay();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::ZSS::Protocol::Robot_Command > command_;
  ::google::protobuf::int32 delay_;
  friend void  protobuf_AddDesc_zss_5fcmd_2eproto();
  friend void protobuf_AssignDesc_zss_5fcmd_2eproto();
  friend void protobuf_ShutdownFile_zss_5fcmd_2eproto();

  void InitAsDefaultInstance();
  static Robots_Command* default_instance_;
};
// -------------------------------------------------------------------

class Robot_Command : public ::google::protobuf::Message {
 public:
  Robot_Command();
  virtual ~Robot_Command();

  Robot_Command(const Robot_Command& from);

  inline Robot_Command& operator=(const Robot_Command& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Robot_Command& default_instance();

  void Swap(Robot_Command* other);

  // implements Message ----------------------------------------------

  Robot_Command* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Robot_Command& from);
  void MergeFrom(const Robot_Command& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 robot_id = 1;
  inline bool has_robot_id() const;
  inline void clear_robot_id();
  static const int kRobotIdFieldNumber = 1;
  inline ::google::protobuf::int32 robot_id() const;
  inline void set_robot_id(::google::protobuf::int32 value);

  // required float velocity_x = 2;
  inline bool has_velocity_x() const;
  inline void clear_velocity_x();
  static const int kVelocityXFieldNumber = 2;
  inline float velocity_x() const;
  inline void set_velocity_x(float value);

  // required float velocity_y = 3;
  inline bool has_velocity_y() const;
  inline void clear_velocity_y();
  static const int kVelocityYFieldNumber = 3;
  inline float velocity_y() const;
  inline void set_velocity_y(float value);

  // required float velocity_r = 4;
  inline bool has_velocity_r() const;
  inline void clear_velocity_r();
  static const int kVelocityRFieldNumber = 4;
  inline float velocity_r() const;
  inline void set_velocity_r(float value);

  // required bool kick = 5;
  inline bool has_kick() const;
  inline void clear_kick();
  static const int kKickFieldNumber = 5;
  inline bool kick() const;
  inline void set_kick(bool value);

  // required float power = 6;
  inline bool has_power() const;
  inline void clear_power();
  static const int kPowerFieldNumber = 6;
  inline float power() const;
  inline void set_power(float value);

  // required float dribbler_spin = 7;
  inline bool has_dribbler_spin() const;
  inline void clear_dribbler_spin();
  static const int kDribblerSpinFieldNumber = 7;
  inline float dribbler_spin() const;
  inline void set_dribbler_spin(float value);

  // optional float current_angle = 8;
  inline bool has_current_angle() const;
  inline void clear_current_angle();
  static const int kCurrentAngleFieldNumber = 8;
  inline float current_angle() const;
  inline void set_current_angle(float value);

  // optional float target_angle = 9;
  inline bool has_target_angle() const;
  inline void clear_target_angle();
  static const int kTargetAngleFieldNumber = 9;
  inline float target_angle() const;
  inline void set_target_angle(float value);

  // @@protoc_insertion_point(class_scope:ZSS.Protocol.Robot_Command)
 private:
  inline void set_has_robot_id();
  inline void clear_has_robot_id();
  inline void set_has_velocity_x();
  inline void clear_has_velocity_x();
  inline void set_has_velocity_y();
  inline void clear_has_velocity_y();
  inline void set_has_velocity_r();
  inline void clear_has_velocity_r();
  inline void set_has_kick();
  inline void clear_has_kick();
  inline void set_has_power();
  inline void clear_has_power();
  inline void set_has_dribbler_spin();
  inline void clear_has_dribbler_spin();
  inline void set_has_current_angle();
  inline void clear_has_current_angle();
  inline void set_has_target_angle();
  inline void clear_has_target_angle();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int32 robot_id_;
  float velocity_x_;
  float velocity_y_;
  float velocity_r_;
  bool kick_;
  float power_;
  float dribbler_spin_;
  float current_angle_;
  float target_angle_;
  friend void  protobuf_AddDesc_zss_5fcmd_2eproto();
  friend void protobuf_AssignDesc_zss_5fcmd_2eproto();
  friend void protobuf_ShutdownFile_zss_5fcmd_2eproto();

  void InitAsDefaultInstance();
  static Robot_Command* default_instance_;
};
// ===================================================================


// ===================================================================

// Robots_Status

// repeated .ZSS.Protocol.Robot_Status robots_status = 1;
inline int Robots_Status::robots_status_size() const {
  return robots_status_.size();
}
inline void Robots_Status::clear_robots_status() {
  robots_status_.Clear();
}
inline const ::ZSS::Protocol::Robot_Status& Robots_Status::robots_status(int index) const {
  // @@protoc_insertion_point(field_get:ZSS.Protocol.Robots_Status.robots_status)
  return robots_status_.Get(index);
}
inline ::ZSS::Protocol::Robot_Status* Robots_Status::mutable_robots_status(int index) {
  // @@protoc_insertion_point(field_mutable:ZSS.Protocol.Robots_Status.robots_status)
  return robots_status_.Mutable(index);
}
inline ::ZSS::Protocol::Robot_Status* Robots_Status::add_robots_status() {
  // @@protoc_insertion_point(field_add:ZSS.Protocol.Robots_Status.robots_status)
  return robots_status_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::ZSS::Protocol::Robot_Status >&
Robots_Status::robots_status() const {
  // @@protoc_insertion_point(field_list:ZSS.Protocol.Robots_Status.robots_status)
  return robots_status_;
}
inline ::google::protobuf::RepeatedPtrField< ::ZSS::Protocol::Robot_Status >*
Robots_Status::mutable_robots_status() {
  // @@protoc_insertion_point(field_mutable_list:ZSS.Protocol.Robots_Status.robots_status)
  return &robots_status_;
}

// -------------------------------------------------------------------

// Robot_Status

// required int32 robot_id = 1;
inline bool Robot_Status::has_robot_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Robot_Status::set_has_robot_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Robot_Status::clear_has_robot_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Robot_Status::clear_robot_id() {
  robot_id_ = 0;
  clear_has_robot_id();
}
inline ::google::protobuf::int32 Robot_Status::robot_id() const {
  // @@protoc_insertion_point(field_get:ZSS.Protocol.Robot_Status.robot_id)
  return robot_id_;
}
inline void Robot_Status::set_robot_id(::google::protobuf::int32 value) {
  set_has_robot_id();
  robot_id_ = value;
  // @@protoc_insertion_point(field_set:ZSS.Protocol.Robot_Status.robot_id)
}

// required bool infrared = 2;
inline bool Robot_Status::has_infrared() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Robot_Status::set_has_infrared() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Robot_Status::clear_has_infrared() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Robot_Status::clear_infrared() {
  infrared_ = false;
  clear_has_infrared();
}
inline bool Robot_Status::infrared() const {
  // @@protoc_insertion_point(field_get:ZSS.Protocol.Robot_Status.infrared)
  return infrared_;
}
inline void Robot_Status::set_infrared(bool value) {
  set_has_infrared();
  infrared_ = value;
  // @@protoc_insertion_point(field_set:ZSS.Protocol.Robot_Status.infrared)
}

// required bool flat_kick = 3;
inline bool Robot_Status::has_flat_kick() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Robot_Status::set_has_flat_kick() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Robot_Status::clear_has_flat_kick() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Robot_Status::clear_flat_kick() {
  flat_kick_ = false;
  clear_has_flat_kick();
}
inline bool Robot_Status::flat_kick() const {
  // @@protoc_insertion_point(field_get:ZSS.Protocol.Robot_Status.flat_kick)
  return flat_kick_;
}
inline void Robot_Status::set_flat_kick(bool value) {
  set_has_flat_kick();
  flat_kick_ = value;
  // @@protoc_insertion_point(field_set:ZSS.Protocol.Robot_Status.flat_kick)
}

// required bool chip_kick = 4;
inline bool Robot_Status::has_chip_kick() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Robot_Status::set_has_chip_kick() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Robot_Status::clear_has_chip_kick() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Robot_Status::clear_chip_kick() {
  chip_kick_ = false;
  clear_has_chip_kick();
}
inline bool Robot_Status::chip_kick() const {
  // @@protoc_insertion_point(field_get:ZSS.Protocol.Robot_Status.chip_kick)
  return chip_kick_;
}
inline void Robot_Status::set_chip_kick(bool value) {
  set_has_chip_kick();
  chip_kick_ = value;
  // @@protoc_insertion_point(field_set:ZSS.Protocol.Robot_Status.chip_kick)
}

// -------------------------------------------------------------------

// Robots_Command

// repeated .ZSS.Protocol.Robot_Command command = 1;
inline int Robots_Command::command_size() const {
  return command_.size();
}
inline void Robots_Command::clear_command() {
  command_.Clear();
}
inline const ::ZSS::Protocol::Robot_Command& Robots_Command::command(int index) const {
  // @@protoc_insertion_point(field_get:ZSS.Protocol.Robots_Command.command)
  return command_.Get(index);
}
inline ::ZSS::Protocol::Robot_Command* Robots_Command::mutable_command(int index) {
  // @@protoc_insertion_point(field_mutable:ZSS.Protocol.Robots_Command.command)
  return command_.Mutable(index);
}
inline ::ZSS::Protocol::Robot_Command* Robots_Command::add_command() {
  // @@protoc_insertion_point(field_add:ZSS.Protocol.Robots_Command.command)
  return command_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::ZSS::Protocol::Robot_Command >&
Robots_Command::command() const {
  // @@protoc_insertion_point(field_list:ZSS.Protocol.Robots_Command.command)
  return command_;
}
inline ::google::protobuf::RepeatedPtrField< ::ZSS::Protocol::Robot_Command >*
Robots_Command::mutable_command() {
  // @@protoc_insertion_point(field_mutable_list:ZSS.Protocol.Robots_Command.command)
  return &command_;
}

// optional int32 delay = 2;
inline bool Robots_Command::has_delay() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Robots_Command::set_has_delay() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Robots_Command::clear_has_delay() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Robots_Command::clear_delay() {
  delay_ = 0;
  clear_has_delay();
}
inline ::google::protobuf::int32 Robots_Command::delay() const {
  // @@protoc_insertion_point(field_get:ZSS.Protocol.Robots_Command.delay)
  return delay_;
}
inline void Robots_Command::set_delay(::google::protobuf::int32 value) {
  set_has_delay();
  delay_ = value;
  // @@protoc_insertion_point(field_set:ZSS.Protocol.Robots_Command.delay)
}

// -------------------------------------------------------------------

// Robot_Command

// required int32 robot_id = 1;
inline bool Robot_Command::has_robot_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Robot_Command::set_has_robot_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Robot_Command::clear_has_robot_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Robot_Command::clear_robot_id() {
  robot_id_ = 0;
  clear_has_robot_id();
}
inline ::google::protobuf::int32 Robot_Command::robot_id() const {
  // @@protoc_insertion_point(field_get:ZSS.Protocol.Robot_Command.robot_id)
  return robot_id_;
}
inline void Robot_Command::set_robot_id(::google::protobuf::int32 value) {
  set_has_robot_id();
  robot_id_ = value;
  // @@protoc_insertion_point(field_set:ZSS.Protocol.Robot_Command.robot_id)
}

// required float velocity_x = 2;
inline bool Robot_Command::has_velocity_x() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Robot_Command::set_has_velocity_x() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Robot_Command::clear_has_velocity_x() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Robot_Command::clear_velocity_x() {
  velocity_x_ = 0;
  clear_has_velocity_x();
}
inline float Robot_Command::velocity_x() const {
  // @@protoc_insertion_point(field_get:ZSS.Protocol.Robot_Command.velocity_x)
  return velocity_x_;
}
inline void Robot_Command::set_velocity_x(float value) {
  set_has_velocity_x();
  velocity_x_ = value;
  // @@protoc_insertion_point(field_set:ZSS.Protocol.Robot_Command.velocity_x)
}

// required float velocity_y = 3;
inline bool Robot_Command::has_velocity_y() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Robot_Command::set_has_velocity_y() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Robot_Command::clear_has_velocity_y() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Robot_Command::clear_velocity_y() {
  velocity_y_ = 0;
  clear_has_velocity_y();
}
inline float Robot_Command::velocity_y() const {
  // @@protoc_insertion_point(field_get:ZSS.Protocol.Robot_Command.velocity_y)
  return velocity_y_;
}
inline void Robot_Command::set_velocity_y(float value) {
  set_has_velocity_y();
  velocity_y_ = value;
  // @@protoc_insertion_point(field_set:ZSS.Protocol.Robot_Command.velocity_y)
}

// required float velocity_r = 4;
inline bool Robot_Command::has_velocity_r() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Robot_Command::set_has_velocity_r() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Robot_Command::clear_has_velocity_r() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Robot_Command::clear_velocity_r() {
  velocity_r_ = 0;
  clear_has_velocity_r();
}
inline float Robot_Command::velocity_r() const {
  // @@protoc_insertion_point(field_get:ZSS.Protocol.Robot_Command.velocity_r)
  return velocity_r_;
}
inline void Robot_Command::set_velocity_r(float value) {
  set_has_velocity_r();
  velocity_r_ = value;
  // @@protoc_insertion_point(field_set:ZSS.Protocol.Robot_Command.velocity_r)
}

// required bool kick = 5;
inline bool Robot_Command::has_kick() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Robot_Command::set_has_kick() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Robot_Command::clear_has_kick() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Robot_Command::clear_kick() {
  kick_ = false;
  clear_has_kick();
}
inline bool Robot_Command::kick() const {
  // @@protoc_insertion_point(field_get:ZSS.Protocol.Robot_Command.kick)
  return kick_;
}
inline void Robot_Command::set_kick(bool value) {
  set_has_kick();
  kick_ = value;
  // @@protoc_insertion_point(field_set:ZSS.Protocol.Robot_Command.kick)
}

// required float power = 6;
inline bool Robot_Command::has_power() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void Robot_Command::set_has_power() {
  _has_bits_[0] |= 0x00000020u;
}
inline void Robot_Command::clear_has_power() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void Robot_Command::clear_power() {
  power_ = 0;
  clear_has_power();
}
inline float Robot_Command::power() const {
  // @@protoc_insertion_point(field_get:ZSS.Protocol.Robot_Command.power)
  return power_;
}
inline void Robot_Command::set_power(float value) {
  set_has_power();
  power_ = value;
  // @@protoc_insertion_point(field_set:ZSS.Protocol.Robot_Command.power)
}

// required float dribbler_spin = 7;
inline bool Robot_Command::has_dribbler_spin() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void Robot_Command::set_has_dribbler_spin() {
  _has_bits_[0] |= 0x00000040u;
}
inline void Robot_Command::clear_has_dribbler_spin() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void Robot_Command::clear_dribbler_spin() {
  dribbler_spin_ = 0;
  clear_has_dribbler_spin();
}
inline float Robot_Command::dribbler_spin() const {
  // @@protoc_insertion_point(field_get:ZSS.Protocol.Robot_Command.dribbler_spin)
  return dribbler_spin_;
}
inline void Robot_Command::set_dribbler_spin(float value) {
  set_has_dribbler_spin();
  dribbler_spin_ = value;
  // @@protoc_insertion_point(field_set:ZSS.Protocol.Robot_Command.dribbler_spin)
}

// optional float current_angle = 8;
inline bool Robot_Command::has_current_angle() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void Robot_Command::set_has_current_angle() {
  _has_bits_[0] |= 0x00000080u;
}
inline void Robot_Command::clear_has_current_angle() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void Robot_Command::clear_current_angle() {
  current_angle_ = 0;
  clear_has_current_angle();
}
inline float Robot_Command::current_angle() const {
  // @@protoc_insertion_point(field_get:ZSS.Protocol.Robot_Command.current_angle)
  return current_angle_;
}
inline void Robot_Command::set_current_angle(float value) {
  set_has_current_angle();
  current_angle_ = value;
  // @@protoc_insertion_point(field_set:ZSS.Protocol.Robot_Command.current_angle)
}

// optional float target_angle = 9;
inline bool Robot_Command::has_target_angle() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void Robot_Command::set_has_target_angle() {
  _has_bits_[0] |= 0x00000100u;
}
inline void Robot_Command::clear_has_target_angle() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void Robot_Command::clear_target_angle() {
  target_angle_ = 0;
  clear_has_target_angle();
}
inline float Robot_Command::target_angle() const {
  // @@protoc_insertion_point(field_get:ZSS.Protocol.Robot_Command.target_angle)
  return target_angle_;
}
inline void Robot_Command::set_target_angle(float value) {
  set_has_target_angle();
  target_angle_ = value;
  // @@protoc_insertion_point(field_set:ZSS.Protocol.Robot_Command.target_angle)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Protocol
}  // namespace ZSS

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_zss_5fcmd_2eproto__INCLUDED
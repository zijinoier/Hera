// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: vision_detection.proto

#ifndef PROTOBUF_vision_5fdetection_2eproto__INCLUDED
#define PROTOBUF_vision_5fdetection_2eproto__INCLUDED

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

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_vision_5fdetection_2eproto();
void protobuf_AssignDesc_vision_5fdetection_2eproto();
void protobuf_ShutdownFile_vision_5fdetection_2eproto();

class Vision_DetectionBall;
class Vision_DetectionRobot;
class Vision_DetectionFrame;

// ===================================================================

class Vision_DetectionBall : public ::google::protobuf::Message {
 public:
  Vision_DetectionBall();
  virtual ~Vision_DetectionBall();

  Vision_DetectionBall(const Vision_DetectionBall& from);

  inline Vision_DetectionBall& operator=(const Vision_DetectionBall& from) {
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
  static const Vision_DetectionBall& default_instance();

  void Swap(Vision_DetectionBall* other);

  // implements Message ----------------------------------------------

  Vision_DetectionBall* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Vision_DetectionBall& from);
  void MergeFrom(const Vision_DetectionBall& from);
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

  // optional float vel_x = 1;
  inline bool has_vel_x() const;
  inline void clear_vel_x();
  static const int kVelXFieldNumber = 1;
  inline float vel_x() const;
  inline void set_vel_x(float value);

  // optional float vel_y = 2;
  inline bool has_vel_y() const;
  inline void clear_vel_y();
  static const int kVelYFieldNumber = 2;
  inline float vel_y() const;
  inline void set_vel_y(float value);

  // optional uint32 area = 3;
  inline bool has_area() const;
  inline void clear_area();
  static const int kAreaFieldNumber = 3;
  inline ::google::protobuf::uint32 area() const;
  inline void set_area(::google::protobuf::uint32 value);

  // required float x = 4;
  inline bool has_x() const;
  inline void clear_x();
  static const int kXFieldNumber = 4;
  inline float x() const;
  inline void set_x(float value);

  // required float y = 5;
  inline bool has_y() const;
  inline void clear_y();
  static const int kYFieldNumber = 5;
  inline float y() const;
  inline void set_y(float value);

  // optional float height = 6;
  inline bool has_height() const;
  inline void clear_height();
  static const int kHeightFieldNumber = 6;
  inline float height() const;
  inline void set_height(float value);

  // optional uint32 ball_state = 7;
  inline bool has_ball_state() const;
  inline void clear_ball_state();
  static const int kBallStateFieldNumber = 7;
  inline ::google::protobuf::uint32 ball_state() const;
  inline void set_ball_state(::google::protobuf::uint32 value);

  // optional uint32 last_touch = 8;
  inline bool has_last_touch() const;
  inline void clear_last_touch();
  static const int kLastTouchFieldNumber = 8;
  inline ::google::protobuf::uint32 last_touch() const;
  inline void set_last_touch(::google::protobuf::uint32 value);

  // required bool valid = 9;
  inline bool has_valid() const;
  inline void clear_valid();
  static const int kValidFieldNumber = 9;
  inline bool valid() const;
  inline void set_valid(bool value);

  // @@protoc_insertion_point(class_scope:Vision_DetectionBall)
 private:
  inline void set_has_vel_x();
  inline void clear_has_vel_x();
  inline void set_has_vel_y();
  inline void clear_has_vel_y();
  inline void set_has_area();
  inline void clear_has_area();
  inline void set_has_x();
  inline void clear_has_x();
  inline void set_has_y();
  inline void clear_has_y();
  inline void set_has_height();
  inline void clear_has_height();
  inline void set_has_ball_state();
  inline void clear_has_ball_state();
  inline void set_has_last_touch();
  inline void clear_has_last_touch();
  inline void set_has_valid();
  inline void clear_has_valid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  float vel_x_;
  float vel_y_;
  ::google::protobuf::uint32 area_;
  float x_;
  float y_;
  float height_;
  ::google::protobuf::uint32 ball_state_;
  ::google::protobuf::uint32 last_touch_;
  bool valid_;
  friend void  protobuf_AddDesc_vision_5fdetection_2eproto();
  friend void protobuf_AssignDesc_vision_5fdetection_2eproto();
  friend void protobuf_ShutdownFile_vision_5fdetection_2eproto();

  void InitAsDefaultInstance();
  static Vision_DetectionBall* default_instance_;
};
// -------------------------------------------------------------------

class Vision_DetectionRobot : public ::google::protobuf::Message {
 public:
  Vision_DetectionRobot();
  virtual ~Vision_DetectionRobot();

  Vision_DetectionRobot(const Vision_DetectionRobot& from);

  inline Vision_DetectionRobot& operator=(const Vision_DetectionRobot& from) {
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
  static const Vision_DetectionRobot& default_instance();

  void Swap(Vision_DetectionRobot* other);

  // implements Message ----------------------------------------------

  Vision_DetectionRobot* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Vision_DetectionRobot& from);
  void MergeFrom(const Vision_DetectionRobot& from);
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

  // required float confidence = 1;
  inline bool has_confidence() const;
  inline void clear_confidence();
  static const int kConfidenceFieldNumber = 1;
  inline float confidence() const;
  inline void set_confidence(float value);

  // optional uint32 robot_id = 2;
  inline bool has_robot_id() const;
  inline void clear_robot_id();
  static const int kRobotIdFieldNumber = 2;
  inline ::google::protobuf::uint32 robot_id() const;
  inline void set_robot_id(::google::protobuf::uint32 value);

  // required float x = 3;
  inline bool has_x() const;
  inline void clear_x();
  static const int kXFieldNumber = 3;
  inline float x() const;
  inline void set_x(float value);

  // required float y = 4;
  inline bool has_y() const;
  inline void clear_y();
  static const int kYFieldNumber = 4;
  inline float y() const;
  inline void set_y(float value);

  // optional float orientation = 5;
  inline bool has_orientation() const;
  inline void clear_orientation();
  static const int kOrientationFieldNumber = 5;
  inline float orientation() const;
  inline void set_orientation(float value);

  // optional float vel_x = 6;
  inline bool has_vel_x() const;
  inline void clear_vel_x();
  static const int kVelXFieldNumber = 6;
  inline float vel_x() const;
  inline void set_vel_x(float value);

  // optional float vel_y = 7;
  inline bool has_vel_y() const;
  inline void clear_vel_y();
  static const int kVelYFieldNumber = 7;
  inline float vel_y() const;
  inline void set_vel_y(float value);

  // optional float rotate_vel = 8;
  inline bool has_rotate_vel() const;
  inline void clear_rotate_vel();
  static const int kRotateVelFieldNumber = 8;
  inline float rotate_vel() const;
  inline void set_rotate_vel(float value);

  // @@protoc_insertion_point(class_scope:Vision_DetectionRobot)
 private:
  inline void set_has_confidence();
  inline void clear_has_confidence();
  inline void set_has_robot_id();
  inline void clear_has_robot_id();
  inline void set_has_x();
  inline void clear_has_x();
  inline void set_has_y();
  inline void clear_has_y();
  inline void set_has_orientation();
  inline void clear_has_orientation();
  inline void set_has_vel_x();
  inline void clear_has_vel_x();
  inline void set_has_vel_y();
  inline void clear_has_vel_y();
  inline void set_has_rotate_vel();
  inline void clear_has_rotate_vel();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  float confidence_;
  ::google::protobuf::uint32 robot_id_;
  float x_;
  float y_;
  float orientation_;
  float vel_x_;
  float vel_y_;
  float rotate_vel_;
  friend void  protobuf_AddDesc_vision_5fdetection_2eproto();
  friend void protobuf_AssignDesc_vision_5fdetection_2eproto();
  friend void protobuf_ShutdownFile_vision_5fdetection_2eproto();

  void InitAsDefaultInstance();
  static Vision_DetectionRobot* default_instance_;
};
// -------------------------------------------------------------------

class Vision_DetectionFrame : public ::google::protobuf::Message {
 public:
  Vision_DetectionFrame();
  virtual ~Vision_DetectionFrame();

  Vision_DetectionFrame(const Vision_DetectionFrame& from);

  inline Vision_DetectionFrame& operator=(const Vision_DetectionFrame& from) {
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
  static const Vision_DetectionFrame& default_instance();

  void Swap(Vision_DetectionFrame* other);

  // implements Message ----------------------------------------------

  Vision_DetectionFrame* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Vision_DetectionFrame& from);
  void MergeFrom(const Vision_DetectionFrame& from);
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

  // required .Vision_DetectionBall balls = 1;
  inline bool has_balls() const;
  inline void clear_balls();
  static const int kBallsFieldNumber = 1;
  inline const ::Vision_DetectionBall& balls() const;
  inline ::Vision_DetectionBall* mutable_balls();
  inline ::Vision_DetectionBall* release_balls();
  inline void set_allocated_balls(::Vision_DetectionBall* balls);

  // repeated .Vision_DetectionRobot robots_yellow = 2;
  inline int robots_yellow_size() const;
  inline void clear_robots_yellow();
  static const int kRobotsYellowFieldNumber = 2;
  inline const ::Vision_DetectionRobot& robots_yellow(int index) const;
  inline ::Vision_DetectionRobot* mutable_robots_yellow(int index);
  inline ::Vision_DetectionRobot* add_robots_yellow();
  inline const ::google::protobuf::RepeatedPtrField< ::Vision_DetectionRobot >&
      robots_yellow() const;
  inline ::google::protobuf::RepeatedPtrField< ::Vision_DetectionRobot >*
      mutable_robots_yellow();

  // repeated .Vision_DetectionRobot robots_blue = 3;
  inline int robots_blue_size() const;
  inline void clear_robots_blue();
  static const int kRobotsBlueFieldNumber = 3;
  inline const ::Vision_DetectionRobot& robots_blue(int index) const;
  inline ::Vision_DetectionRobot* mutable_robots_blue(int index);
  inline ::Vision_DetectionRobot* add_robots_blue();
  inline const ::google::protobuf::RepeatedPtrField< ::Vision_DetectionRobot >&
      robots_blue() const;
  inline ::google::protobuf::RepeatedPtrField< ::Vision_DetectionRobot >*
      mutable_robots_blue();

  // @@protoc_insertion_point(class_scope:Vision_DetectionFrame)
 private:
  inline void set_has_balls();
  inline void clear_has_balls();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::Vision_DetectionBall* balls_;
  ::google::protobuf::RepeatedPtrField< ::Vision_DetectionRobot > robots_yellow_;
  ::google::protobuf::RepeatedPtrField< ::Vision_DetectionRobot > robots_blue_;
  friend void  protobuf_AddDesc_vision_5fdetection_2eproto();
  friend void protobuf_AssignDesc_vision_5fdetection_2eproto();
  friend void protobuf_ShutdownFile_vision_5fdetection_2eproto();

  void InitAsDefaultInstance();
  static Vision_DetectionFrame* default_instance_;
};
// ===================================================================


// ===================================================================

// Vision_DetectionBall

// optional float vel_x = 1;
inline bool Vision_DetectionBall::has_vel_x() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Vision_DetectionBall::set_has_vel_x() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Vision_DetectionBall::clear_has_vel_x() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Vision_DetectionBall::clear_vel_x() {
  vel_x_ = 0;
  clear_has_vel_x();
}
inline float Vision_DetectionBall::vel_x() const {
  // @@protoc_insertion_point(field_get:Vision_DetectionBall.vel_x)
  return vel_x_;
}
inline void Vision_DetectionBall::set_vel_x(float value) {
  set_has_vel_x();
  vel_x_ = value;
  // @@protoc_insertion_point(field_set:Vision_DetectionBall.vel_x)
}

// optional float vel_y = 2;
inline bool Vision_DetectionBall::has_vel_y() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Vision_DetectionBall::set_has_vel_y() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Vision_DetectionBall::clear_has_vel_y() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Vision_DetectionBall::clear_vel_y() {
  vel_y_ = 0;
  clear_has_vel_y();
}
inline float Vision_DetectionBall::vel_y() const {
  // @@protoc_insertion_point(field_get:Vision_DetectionBall.vel_y)
  return vel_y_;
}
inline void Vision_DetectionBall::set_vel_y(float value) {
  set_has_vel_y();
  vel_y_ = value;
  // @@protoc_insertion_point(field_set:Vision_DetectionBall.vel_y)
}

// optional uint32 area = 3;
inline bool Vision_DetectionBall::has_area() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Vision_DetectionBall::set_has_area() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Vision_DetectionBall::clear_has_area() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Vision_DetectionBall::clear_area() {
  area_ = 0u;
  clear_has_area();
}
inline ::google::protobuf::uint32 Vision_DetectionBall::area() const {
  // @@protoc_insertion_point(field_get:Vision_DetectionBall.area)
  return area_;
}
inline void Vision_DetectionBall::set_area(::google::protobuf::uint32 value) {
  set_has_area();
  area_ = value;
  // @@protoc_insertion_point(field_set:Vision_DetectionBall.area)
}

// required float x = 4;
inline bool Vision_DetectionBall::has_x() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Vision_DetectionBall::set_has_x() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Vision_DetectionBall::clear_has_x() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Vision_DetectionBall::clear_x() {
  x_ = 0;
  clear_has_x();
}
inline float Vision_DetectionBall::x() const {
  // @@protoc_insertion_point(field_get:Vision_DetectionBall.x)
  return x_;
}
inline void Vision_DetectionBall::set_x(float value) {
  set_has_x();
  x_ = value;
  // @@protoc_insertion_point(field_set:Vision_DetectionBall.x)
}

// required float y = 5;
inline bool Vision_DetectionBall::has_y() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Vision_DetectionBall::set_has_y() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Vision_DetectionBall::clear_has_y() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Vision_DetectionBall::clear_y() {
  y_ = 0;
  clear_has_y();
}
inline float Vision_DetectionBall::y() const {
  // @@protoc_insertion_point(field_get:Vision_DetectionBall.y)
  return y_;
}
inline void Vision_DetectionBall::set_y(float value) {
  set_has_y();
  y_ = value;
  // @@protoc_insertion_point(field_set:Vision_DetectionBall.y)
}

// optional float height = 6;
inline bool Vision_DetectionBall::has_height() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void Vision_DetectionBall::set_has_height() {
  _has_bits_[0] |= 0x00000020u;
}
inline void Vision_DetectionBall::clear_has_height() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void Vision_DetectionBall::clear_height() {
  height_ = 0;
  clear_has_height();
}
inline float Vision_DetectionBall::height() const {
  // @@protoc_insertion_point(field_get:Vision_DetectionBall.height)
  return height_;
}
inline void Vision_DetectionBall::set_height(float value) {
  set_has_height();
  height_ = value;
  // @@protoc_insertion_point(field_set:Vision_DetectionBall.height)
}

// optional uint32 ball_state = 7;
inline bool Vision_DetectionBall::has_ball_state() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void Vision_DetectionBall::set_has_ball_state() {
  _has_bits_[0] |= 0x00000040u;
}
inline void Vision_DetectionBall::clear_has_ball_state() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void Vision_DetectionBall::clear_ball_state() {
  ball_state_ = 0u;
  clear_has_ball_state();
}
inline ::google::protobuf::uint32 Vision_DetectionBall::ball_state() const {
  // @@protoc_insertion_point(field_get:Vision_DetectionBall.ball_state)
  return ball_state_;
}
inline void Vision_DetectionBall::set_ball_state(::google::protobuf::uint32 value) {
  set_has_ball_state();
  ball_state_ = value;
  // @@protoc_insertion_point(field_set:Vision_DetectionBall.ball_state)
}

// optional uint32 last_touch = 8;
inline bool Vision_DetectionBall::has_last_touch() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void Vision_DetectionBall::set_has_last_touch() {
  _has_bits_[0] |= 0x00000080u;
}
inline void Vision_DetectionBall::clear_has_last_touch() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void Vision_DetectionBall::clear_last_touch() {
  last_touch_ = 0u;
  clear_has_last_touch();
}
inline ::google::protobuf::uint32 Vision_DetectionBall::last_touch() const {
  // @@protoc_insertion_point(field_get:Vision_DetectionBall.last_touch)
  return last_touch_;
}
inline void Vision_DetectionBall::set_last_touch(::google::protobuf::uint32 value) {
  set_has_last_touch();
  last_touch_ = value;
  // @@protoc_insertion_point(field_set:Vision_DetectionBall.last_touch)
}

// required bool valid = 9;
inline bool Vision_DetectionBall::has_valid() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void Vision_DetectionBall::set_has_valid() {
  _has_bits_[0] |= 0x00000100u;
}
inline void Vision_DetectionBall::clear_has_valid() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void Vision_DetectionBall::clear_valid() {
  valid_ = false;
  clear_has_valid();
}
inline bool Vision_DetectionBall::valid() const {
  // @@protoc_insertion_point(field_get:Vision_DetectionBall.valid)
  return valid_;
}
inline void Vision_DetectionBall::set_valid(bool value) {
  set_has_valid();
  valid_ = value;
  // @@protoc_insertion_point(field_set:Vision_DetectionBall.valid)
}

// -------------------------------------------------------------------

// Vision_DetectionRobot

// required float confidence = 1;
inline bool Vision_DetectionRobot::has_confidence() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Vision_DetectionRobot::set_has_confidence() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Vision_DetectionRobot::clear_has_confidence() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Vision_DetectionRobot::clear_confidence() {
  confidence_ = 0;
  clear_has_confidence();
}
inline float Vision_DetectionRobot::confidence() const {
  // @@protoc_insertion_point(field_get:Vision_DetectionRobot.confidence)
  return confidence_;
}
inline void Vision_DetectionRobot::set_confidence(float value) {
  set_has_confidence();
  confidence_ = value;
  // @@protoc_insertion_point(field_set:Vision_DetectionRobot.confidence)
}

// optional uint32 robot_id = 2;
inline bool Vision_DetectionRobot::has_robot_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Vision_DetectionRobot::set_has_robot_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Vision_DetectionRobot::clear_has_robot_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Vision_DetectionRobot::clear_robot_id() {
  robot_id_ = 0u;
  clear_has_robot_id();
}
inline ::google::protobuf::uint32 Vision_DetectionRobot::robot_id() const {
  // @@protoc_insertion_point(field_get:Vision_DetectionRobot.robot_id)
  return robot_id_;
}
inline void Vision_DetectionRobot::set_robot_id(::google::protobuf::uint32 value) {
  set_has_robot_id();
  robot_id_ = value;
  // @@protoc_insertion_point(field_set:Vision_DetectionRobot.robot_id)
}

// required float x = 3;
inline bool Vision_DetectionRobot::has_x() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Vision_DetectionRobot::set_has_x() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Vision_DetectionRobot::clear_has_x() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Vision_DetectionRobot::clear_x() {
  x_ = 0;
  clear_has_x();
}
inline float Vision_DetectionRobot::x() const {
  // @@protoc_insertion_point(field_get:Vision_DetectionRobot.x)
  return x_;
}
inline void Vision_DetectionRobot::set_x(float value) {
  set_has_x();
  x_ = value;
  // @@protoc_insertion_point(field_set:Vision_DetectionRobot.x)
}

// required float y = 4;
inline bool Vision_DetectionRobot::has_y() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Vision_DetectionRobot::set_has_y() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Vision_DetectionRobot::clear_has_y() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Vision_DetectionRobot::clear_y() {
  y_ = 0;
  clear_has_y();
}
inline float Vision_DetectionRobot::y() const {
  // @@protoc_insertion_point(field_get:Vision_DetectionRobot.y)
  return y_;
}
inline void Vision_DetectionRobot::set_y(float value) {
  set_has_y();
  y_ = value;
  // @@protoc_insertion_point(field_set:Vision_DetectionRobot.y)
}

// optional float orientation = 5;
inline bool Vision_DetectionRobot::has_orientation() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Vision_DetectionRobot::set_has_orientation() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Vision_DetectionRobot::clear_has_orientation() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Vision_DetectionRobot::clear_orientation() {
  orientation_ = 0;
  clear_has_orientation();
}
inline float Vision_DetectionRobot::orientation() const {
  // @@protoc_insertion_point(field_get:Vision_DetectionRobot.orientation)
  return orientation_;
}
inline void Vision_DetectionRobot::set_orientation(float value) {
  set_has_orientation();
  orientation_ = value;
  // @@protoc_insertion_point(field_set:Vision_DetectionRobot.orientation)
}

// optional float vel_x = 6;
inline bool Vision_DetectionRobot::has_vel_x() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void Vision_DetectionRobot::set_has_vel_x() {
  _has_bits_[0] |= 0x00000020u;
}
inline void Vision_DetectionRobot::clear_has_vel_x() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void Vision_DetectionRobot::clear_vel_x() {
  vel_x_ = 0;
  clear_has_vel_x();
}
inline float Vision_DetectionRobot::vel_x() const {
  // @@protoc_insertion_point(field_get:Vision_DetectionRobot.vel_x)
  return vel_x_;
}
inline void Vision_DetectionRobot::set_vel_x(float value) {
  set_has_vel_x();
  vel_x_ = value;
  // @@protoc_insertion_point(field_set:Vision_DetectionRobot.vel_x)
}

// optional float vel_y = 7;
inline bool Vision_DetectionRobot::has_vel_y() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void Vision_DetectionRobot::set_has_vel_y() {
  _has_bits_[0] |= 0x00000040u;
}
inline void Vision_DetectionRobot::clear_has_vel_y() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void Vision_DetectionRobot::clear_vel_y() {
  vel_y_ = 0;
  clear_has_vel_y();
}
inline float Vision_DetectionRobot::vel_y() const {
  // @@protoc_insertion_point(field_get:Vision_DetectionRobot.vel_y)
  return vel_y_;
}
inline void Vision_DetectionRobot::set_vel_y(float value) {
  set_has_vel_y();
  vel_y_ = value;
  // @@protoc_insertion_point(field_set:Vision_DetectionRobot.vel_y)
}

// optional float rotate_vel = 8;
inline bool Vision_DetectionRobot::has_rotate_vel() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void Vision_DetectionRobot::set_has_rotate_vel() {
  _has_bits_[0] |= 0x00000080u;
}
inline void Vision_DetectionRobot::clear_has_rotate_vel() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void Vision_DetectionRobot::clear_rotate_vel() {
  rotate_vel_ = 0;
  clear_has_rotate_vel();
}
inline float Vision_DetectionRobot::rotate_vel() const {
  // @@protoc_insertion_point(field_get:Vision_DetectionRobot.rotate_vel)
  return rotate_vel_;
}
inline void Vision_DetectionRobot::set_rotate_vel(float value) {
  set_has_rotate_vel();
  rotate_vel_ = value;
  // @@protoc_insertion_point(field_set:Vision_DetectionRobot.rotate_vel)
}

// -------------------------------------------------------------------

// Vision_DetectionFrame

// required .Vision_DetectionBall balls = 1;
inline bool Vision_DetectionFrame::has_balls() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Vision_DetectionFrame::set_has_balls() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Vision_DetectionFrame::clear_has_balls() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Vision_DetectionFrame::clear_balls() {
  if (balls_ != NULL) balls_->::Vision_DetectionBall::Clear();
  clear_has_balls();
}
inline const ::Vision_DetectionBall& Vision_DetectionFrame::balls() const {
  // @@protoc_insertion_point(field_get:Vision_DetectionFrame.balls)
  return balls_ != NULL ? *balls_ : *default_instance_->balls_;
}
inline ::Vision_DetectionBall* Vision_DetectionFrame::mutable_balls() {
  set_has_balls();
  if (balls_ == NULL) balls_ = new ::Vision_DetectionBall;
  // @@protoc_insertion_point(field_mutable:Vision_DetectionFrame.balls)
  return balls_;
}
inline ::Vision_DetectionBall* Vision_DetectionFrame::release_balls() {
  clear_has_balls();
  ::Vision_DetectionBall* temp = balls_;
  balls_ = NULL;
  return temp;
}
inline void Vision_DetectionFrame::set_allocated_balls(::Vision_DetectionBall* balls) {
  delete balls_;
  balls_ = balls;
  if (balls) {
    set_has_balls();
  } else {
    clear_has_balls();
  }
  // @@protoc_insertion_point(field_set_allocated:Vision_DetectionFrame.balls)
}

// repeated .Vision_DetectionRobot robots_yellow = 2;
inline int Vision_DetectionFrame::robots_yellow_size() const {
  return robots_yellow_.size();
}
inline void Vision_DetectionFrame::clear_robots_yellow() {
  robots_yellow_.Clear();
}
inline const ::Vision_DetectionRobot& Vision_DetectionFrame::robots_yellow(int index) const {
  // @@protoc_insertion_point(field_get:Vision_DetectionFrame.robots_yellow)
  return robots_yellow_.Get(index);
}
inline ::Vision_DetectionRobot* Vision_DetectionFrame::mutable_robots_yellow(int index) {
  // @@protoc_insertion_point(field_mutable:Vision_DetectionFrame.robots_yellow)
  return robots_yellow_.Mutable(index);
}
inline ::Vision_DetectionRobot* Vision_DetectionFrame::add_robots_yellow() {
  // @@protoc_insertion_point(field_add:Vision_DetectionFrame.robots_yellow)
  return robots_yellow_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Vision_DetectionRobot >&
Vision_DetectionFrame::robots_yellow() const {
  // @@protoc_insertion_point(field_list:Vision_DetectionFrame.robots_yellow)
  return robots_yellow_;
}
inline ::google::protobuf::RepeatedPtrField< ::Vision_DetectionRobot >*
Vision_DetectionFrame::mutable_robots_yellow() {
  // @@protoc_insertion_point(field_mutable_list:Vision_DetectionFrame.robots_yellow)
  return &robots_yellow_;
}

// repeated .Vision_DetectionRobot robots_blue = 3;
inline int Vision_DetectionFrame::robots_blue_size() const {
  return robots_blue_.size();
}
inline void Vision_DetectionFrame::clear_robots_blue() {
  robots_blue_.Clear();
}
inline const ::Vision_DetectionRobot& Vision_DetectionFrame::robots_blue(int index) const {
  // @@protoc_insertion_point(field_get:Vision_DetectionFrame.robots_blue)
  return robots_blue_.Get(index);
}
inline ::Vision_DetectionRobot* Vision_DetectionFrame::mutable_robots_blue(int index) {
  // @@protoc_insertion_point(field_mutable:Vision_DetectionFrame.robots_blue)
  return robots_blue_.Mutable(index);
}
inline ::Vision_DetectionRobot* Vision_DetectionFrame::add_robots_blue() {
  // @@protoc_insertion_point(field_add:Vision_DetectionFrame.robots_blue)
  return robots_blue_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Vision_DetectionRobot >&
Vision_DetectionFrame::robots_blue() const {
  // @@protoc_insertion_point(field_list:Vision_DetectionFrame.robots_blue)
  return robots_blue_;
}
inline ::google::protobuf::RepeatedPtrField< ::Vision_DetectionRobot >*
Vision_DetectionFrame::mutable_robots_blue() {
  // @@protoc_insertion_point(field_mutable_list:Vision_DetectionFrame.robots_blue)
  return &robots_blue_;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_vision_5fdetection_2eproto__INCLUDED

// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: grSimMessage.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "grSimMessage.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace grSimMessage {

namespace {

const ::google::protobuf::Descriptor* grSimInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  grSimInfo_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_grSimMessage_2eproto() {
  protobuf_AddDesc_grSimMessage_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "grSimMessage.proto");
  GOOGLE_CHECK(file != NULL);
  grSimInfo_descriptor_ = file->message_type(0);
  static const int grSimInfo_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(grSimInfo, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(grSimInfo, isinfrared_),
  };
  grSimInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      grSimInfo_descriptor_,
      grSimInfo::default_instance_,
      grSimInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(grSimInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(grSimInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(grSimInfo));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_grSimMessage_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    grSimInfo_descriptor_, &grSimInfo::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_grSimMessage_2eproto() {
  delete grSimInfo::default_instance_;
  delete grSimInfo_reflection_;
}

void protobuf_AddDesc_grSimMessage_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\022grSimMessage.proto\022\014grSimMessage\"+\n\tgr"
    "SimInfo\022\n\n\002id\030\001 \002(\r\022\022\n\nisInfrared\030\002 \001(\010", 79);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "grSimMessage.proto", &protobuf_RegisterTypes);
  grSimInfo::default_instance_ = new grSimInfo();
  grSimInfo::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_grSimMessage_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_grSimMessage_2eproto {
  StaticDescriptorInitializer_grSimMessage_2eproto() {
    protobuf_AddDesc_grSimMessage_2eproto();
  }
} static_descriptor_initializer_grSimMessage_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int grSimInfo::kIdFieldNumber;
const int grSimInfo::kIsInfraredFieldNumber;
#endif  // !_MSC_VER

grSimInfo::grSimInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:grSimMessage.grSimInfo)
}

void grSimInfo::InitAsDefaultInstance() {
}

grSimInfo::grSimInfo(const grSimInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:grSimMessage.grSimInfo)
}

void grSimInfo::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0u;
  isinfrared_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

grSimInfo::~grSimInfo() {
  // @@protoc_insertion_point(destructor:grSimMessage.grSimInfo)
  SharedDtor();
}

void grSimInfo::SharedDtor() {
  if (this != default_instance_) {
  }
}

void grSimInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* grSimInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return grSimInfo_descriptor_;
}

const grSimInfo& grSimInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_grSimMessage_2eproto();
  return *default_instance_;
}

grSimInfo* grSimInfo::default_instance_ = NULL;

grSimInfo* grSimInfo::New() const {
  return new grSimInfo;
}

void grSimInfo::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<grSimInfo*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(id_, isinfrared_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool grSimInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:grSimMessage.grSimInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_isInfrared;
        break;
      }

      // optional bool isInfrared = 2;
      case 2: {
        if (tag == 16) {
         parse_isInfrared:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &isinfrared_)));
          set_has_isinfrared();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:grSimMessage.grSimInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:grSimMessage.grSimInfo)
  return false;
#undef DO_
}

void grSimInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:grSimMessage.grSimInfo)
  // required uint32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->id(), output);
  }

  // optional bool isInfrared = 2;
  if (has_isinfrared()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->isinfrared(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:grSimMessage.grSimInfo)
}

::google::protobuf::uint8* grSimInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:grSimMessage.grSimInfo)
  // required uint32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->id(), target);
  }

  // optional bool isInfrared = 2;
  if (has_isinfrared()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(2, this->isinfrared(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:grSimMessage.grSimInfo)
  return target;
}

int grSimInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->id());
    }

    // optional bool isInfrared = 2;
    if (has_isinfrared()) {
      total_size += 1 + 1;
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void grSimInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const grSimInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const grSimInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void grSimInfo::MergeFrom(const grSimInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_isinfrared()) {
      set_isinfrared(from.isinfrared());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void grSimInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void grSimInfo::CopyFrom(const grSimInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool grSimInfo::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void grSimInfo::Swap(grSimInfo* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(isinfrared_, other->isinfrared_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata grSimInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = grSimInfo_descriptor_;
  metadata.reflection = grSimInfo_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace grSimMessage

// @@protoc_insertion_point(global_scope)
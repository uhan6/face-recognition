// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: my_proto.MsgCom.proto

#include "my_proto.MsgCom.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)
namespace my_proto {
class MsgComDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<MsgCom>
      _instance;
} _MsgCom_default_instance_;
}  // namespace my_proto
namespace protobuf_my_5fproto_2eMsgCom_2eproto {
void InitDefaultsMsgComImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::my_proto::_MsgCom_default_instance_;
    new (ptr) ::my_proto::MsgCom();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::my_proto::MsgCom::InitAsDefaultInstance();
}

void InitDefaultsMsgCom() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsMsgComImpl);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::my_proto::MsgCom, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::my_proto::MsgCom, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::my_proto::MsgCom, num_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::my_proto::MsgCom, id_name_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::my_proto::MsgCom, name_index_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::my_proto::MsgCom, images_labels_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::my_proto::MsgCom, cascade_path_),
  4,
  0,
  1,
  2,
  3,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 10, sizeof(::my_proto::MsgCom)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::my_proto::_MsgCom_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "my_proto.MsgCom.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\025my_proto.MsgCom.proto\022\010my_proto\"g\n\006Msg"
      "Com\022\013\n\003num\030\001 \002(\005\022\017\n\007id_name\030\002 \001(\t\022\022\n\nnam"
      "e_index\030\003 \001(\t\022\025\n\rimages_labels\030\004 \001(\t\022\024\n\014"
      "cascade_path\030\005 \001(\t"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 138);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "my_proto.MsgCom.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_my_5fproto_2eMsgCom_2eproto
namespace my_proto {

// ===================================================================

void MsgCom::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int MsgCom::kNumFieldNumber;
const int MsgCom::kIdNameFieldNumber;
const int MsgCom::kNameIndexFieldNumber;
const int MsgCom::kImagesLabelsFieldNumber;
const int MsgCom::kCascadePathFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

MsgCom::MsgCom()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_my_5fproto_2eMsgCom_2eproto::InitDefaultsMsgCom();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:my_proto.MsgCom)
}
MsgCom::MsgCom(const MsgCom& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  id_name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_id_name()) {
    id_name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.id_name_);
  }
  name_index_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_name_index()) {
    name_index_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_index_);
  }
  images_labels_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_images_labels()) {
    images_labels_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.images_labels_);
  }
  cascade_path_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_cascade_path()) {
    cascade_path_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.cascade_path_);
  }
  num_ = from.num_;
  // @@protoc_insertion_point(copy_constructor:my_proto.MsgCom)
}

void MsgCom::SharedCtor() {
  _cached_size_ = 0;
  id_name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  name_index_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  images_labels_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  cascade_path_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  num_ = 0;
}

MsgCom::~MsgCom() {
  // @@protoc_insertion_point(destructor:my_proto.MsgCom)
  SharedDtor();
}

void MsgCom::SharedDtor() {
  id_name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  name_index_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  images_labels_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  cascade_path_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void MsgCom::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MsgCom::descriptor() {
  ::protobuf_my_5fproto_2eMsgCom_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_my_5fproto_2eMsgCom_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const MsgCom& MsgCom::default_instance() {
  ::protobuf_my_5fproto_2eMsgCom_2eproto::InitDefaultsMsgCom();
  return *internal_default_instance();
}

MsgCom* MsgCom::New(::google::protobuf::Arena* arena) const {
  MsgCom* n = new MsgCom;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void MsgCom::Clear() {
// @@protoc_insertion_point(message_clear_start:my_proto.MsgCom)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 15u) {
    if (cached_has_bits & 0x00000001u) {
      GOOGLE_DCHECK(!id_name_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*id_name_.UnsafeRawStringPointer())->clear();
    }
    if (cached_has_bits & 0x00000002u) {
      GOOGLE_DCHECK(!name_index_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*name_index_.UnsafeRawStringPointer())->clear();
    }
    if (cached_has_bits & 0x00000004u) {
      GOOGLE_DCHECK(!images_labels_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*images_labels_.UnsafeRawStringPointer())->clear();
    }
    if (cached_has_bits & 0x00000008u) {
      GOOGLE_DCHECK(!cascade_path_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*cascade_path_.UnsafeRawStringPointer())->clear();
    }
  }
  num_ = 0;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool MsgCom::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:my_proto.MsgCom)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 num = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          set_has_num();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &num_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string id_name = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_id_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->id_name().data(), static_cast<int>(this->id_name().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "my_proto.MsgCom.id_name");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string name_index = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name_index()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->name_index().data(), static_cast<int>(this->name_index().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "my_proto.MsgCom.name_index");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string images_labels = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_images_labels()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->images_labels().data(), static_cast<int>(this->images_labels().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "my_proto.MsgCom.images_labels");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string cascade_path = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(42u /* 42 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_cascade_path()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->cascade_path().data(), static_cast<int>(this->cascade_path().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "my_proto.MsgCom.cascade_path");
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:my_proto.MsgCom)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:my_proto.MsgCom)
  return false;
#undef DO_
}

void MsgCom::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:my_proto.MsgCom)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required int32 num = 1;
  if (cached_has_bits & 0x00000010u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->num(), output);
  }

  // optional string id_name = 2;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->id_name().data(), static_cast<int>(this->id_name().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "my_proto.MsgCom.id_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->id_name(), output);
  }

  // optional string name_index = 3;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name_index().data(), static_cast<int>(this->name_index().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "my_proto.MsgCom.name_index");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->name_index(), output);
  }

  // optional string images_labels = 4;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->images_labels().data(), static_cast<int>(this->images_labels().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "my_proto.MsgCom.images_labels");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->images_labels(), output);
  }

  // optional string cascade_path = 5;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->cascade_path().data(), static_cast<int>(this->cascade_path().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "my_proto.MsgCom.cascade_path");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      5, this->cascade_path(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:my_proto.MsgCom)
}

::google::protobuf::uint8* MsgCom::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:my_proto.MsgCom)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required int32 num = 1;
  if (cached_has_bits & 0x00000010u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->num(), target);
  }

  // optional string id_name = 2;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->id_name().data(), static_cast<int>(this->id_name().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "my_proto.MsgCom.id_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->id_name(), target);
  }

  // optional string name_index = 3;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name_index().data(), static_cast<int>(this->name_index().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "my_proto.MsgCom.name_index");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->name_index(), target);
  }

  // optional string images_labels = 4;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->images_labels().data(), static_cast<int>(this->images_labels().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "my_proto.MsgCom.images_labels");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->images_labels(), target);
  }

  // optional string cascade_path = 5;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->cascade_path().data(), static_cast<int>(this->cascade_path().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "my_proto.MsgCom.cascade_path");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->cascade_path(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:my_proto.MsgCom)
  return target;
}

size_t MsgCom::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:my_proto.MsgCom)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  // required int32 num = 1;
  if (has_num()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->num());
  }
  if (_has_bits_[0 / 32] & 15u) {
    // optional string id_name = 2;
    if (has_id_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->id_name());
    }

    // optional string name_index = 3;
    if (has_name_index()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name_index());
    }

    // optional string images_labels = 4;
    if (has_images_labels()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->images_labels());
    }

    // optional string cascade_path = 5;
    if (has_cascade_path()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->cascade_path());
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MsgCom::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:my_proto.MsgCom)
  GOOGLE_DCHECK_NE(&from, this);
  const MsgCom* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const MsgCom>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:my_proto.MsgCom)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:my_proto.MsgCom)
    MergeFrom(*source);
  }
}

void MsgCom::MergeFrom(const MsgCom& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:my_proto.MsgCom)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 31u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_id_name();
      id_name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.id_name_);
    }
    if (cached_has_bits & 0x00000002u) {
      set_has_name_index();
      name_index_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_index_);
    }
    if (cached_has_bits & 0x00000004u) {
      set_has_images_labels();
      images_labels_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.images_labels_);
    }
    if (cached_has_bits & 0x00000008u) {
      set_has_cascade_path();
      cascade_path_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.cascade_path_);
    }
    if (cached_has_bits & 0x00000010u) {
      num_ = from.num_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void MsgCom::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:my_proto.MsgCom)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MsgCom::CopyFrom(const MsgCom& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:my_proto.MsgCom)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MsgCom::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000010) != 0x00000010) return false;
  return true;
}

void MsgCom::Swap(MsgCom* other) {
  if (other == this) return;
  InternalSwap(other);
}
void MsgCom::InternalSwap(MsgCom* other) {
  using std::swap;
  id_name_.Swap(&other->id_name_);
  name_index_.Swap(&other->name_index_);
  images_labels_.Swap(&other->images_labels_);
  cascade_path_.Swap(&other->cascade_path_);
  swap(num_, other->num_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata MsgCom::GetMetadata() const {
  protobuf_my_5fproto_2eMsgCom_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_my_5fproto_2eMsgCom_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace my_proto

// @@protoc_insertion_point(global_scope)
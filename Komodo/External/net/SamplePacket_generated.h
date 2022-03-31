// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_SAMPLEPACKET_SAMPLEPACKET_H_
#define FLATBUFFERS_GENERATED_SAMPLEPACKET_SAMPLEPACKET_H_

#include "flatbuffers/flatbuffers.h"

namespace SamplePacket {

struct Vec3;

struct textREQ;
struct textREQBuilder;

struct textACK;
struct textACKBuilder;

struct Login_req;
struct Login_reqBuilder;

enum Color {
  Color_Red = 1,
  Color_Green = 2,
  Color_Blue = 3,
  Color_MIN = Color_Red,
  Color_MAX = Color_Blue
};

inline const Color (&EnumValuesColor())[3] {
  static const Color values[] = {
    Color_Red,
    Color_Green,
    Color_Blue
  };
  return values;
}

inline const char * const *EnumNamesColor() {
  static const char * const names[4] = {
    "Red",
    "Green",
    "Blue",
    nullptr
  };
  return names;
}

inline const char *EnumNameColor(Color e) {
  if (flatbuffers::IsOutRange(e, Color_Red, Color_Blue)) return "";
  const size_t index = static_cast<size_t>(e) - static_cast<size_t>(Color_Red);
  return EnumNamesColor()[index];
}

enum Any {
  Any_NONE = 0,
  Any_textREQ = 1,
  Any_textACK = 2,
  Any_MIN = Any_NONE,
  Any_MAX = Any_textACK
};

inline const Any (&EnumValuesAny())[3] {
  static const Any values[] = {
    Any_NONE,
    Any_textREQ,
    Any_textACK
  };
  return values;
}

inline const char * const *EnumNamesAny() {
  static const char * const names[4] = {
    "NONE",
    "textREQ",
    "textACK",
    nullptr
  };
  return names;
}

inline const char *EnumNameAny(Any e) {
  if (flatbuffers::IsOutRange(e, Any_NONE, Any_textACK)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesAny()[index];
}

template<typename T> struct AnyTraits {
  static const Any enum_value = Any_NONE;
};

template<> struct AnyTraits<SamplePacket::textREQ> {
  static const Any enum_value = Any_textREQ;
};

template<> struct AnyTraits<SamplePacket::textACK> {
  static const Any enum_value = Any_textACK;
};

bool VerifyAny(flatbuffers::Verifier &verifier, const void *obj, Any type);
bool VerifyAnyVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

FLATBUFFERS_MANUALLY_ALIGNED_STRUCT(4) Vec3 FLATBUFFERS_FINAL_CLASS {
 private:
  float v_[3];

 public:
  Vec3() {
    memset(static_cast<void *>(this), 0, sizeof(Vec3));
  }
  const flatbuffers::Array<float, 3> *v() const {
    return reinterpret_cast<const flatbuffers::Array<float, 3> *>(v_);
  }
};
FLATBUFFERS_STRUCT_END(Vec3, 12);

struct textREQ FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef textREQBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_TEXT = 4
  };
  const flatbuffers::String *text() const {
    return GetPointer<const flatbuffers::String *>(VT_TEXT);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_TEXT) &&
           verifier.VerifyString(text()) &&
           verifier.EndTable();
  }
};

struct textREQBuilder {
  typedef textREQ Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_text(flatbuffers::Offset<flatbuffers::String> text) {
    fbb_.AddOffset(textREQ::VT_TEXT, text);
  }
  explicit textREQBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  textREQBuilder &operator=(const textREQBuilder &);
  flatbuffers::Offset<textREQ> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<textREQ>(end);
    return o;
  }
};

inline flatbuffers::Offset<textREQ> CreatetextREQ(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> text = 0) {
  textREQBuilder builder_(_fbb);
  builder_.add_text(text);
  return builder_.Finish();
}

inline flatbuffers::Offset<textREQ> CreatetextREQDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *text = nullptr) {
  auto text__ = text ? _fbb.CreateString(text) : 0;
  return SamplePacket::CreatetextREQ(
      _fbb,
      text__);
}

struct textACK FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef textACKBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_TEXT = 4
  };
  const flatbuffers::String *text() const {
    return GetPointer<const flatbuffers::String *>(VT_TEXT);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_TEXT) &&
           verifier.VerifyString(text()) &&
           verifier.EndTable();
  }
};

struct textACKBuilder {
  typedef textACK Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_text(flatbuffers::Offset<flatbuffers::String> text) {
    fbb_.AddOffset(textACK::VT_TEXT, text);
  }
  explicit textACKBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  textACKBuilder &operator=(const textACKBuilder &);
  flatbuffers::Offset<textACK> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<textACK>(end);
    return o;
  }
};

inline flatbuffers::Offset<textACK> CreatetextACK(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> text = 0) {
  textACKBuilder builder_(_fbb);
  builder_.add_text(text);
  return builder_.Finish();
}

inline flatbuffers::Offset<textACK> CreatetextACKDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *text = nullptr) {
  auto text__ = text ? _fbb.CreateString(text) : 0;
  return SamplePacket::CreatetextACK(
      _fbb,
      text__);
}

struct Login_req FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef Login_reqBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ID = 4,
    VT_PW = 6
  };
  const flatbuffers::String *id() const {
    return GetPointer<const flatbuffers::String *>(VT_ID);
  }
  const flatbuffers::String *pw() const {
    return GetPointer<const flatbuffers::String *>(VT_PW);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_ID) &&
           verifier.VerifyString(id()) &&
           VerifyOffset(verifier, VT_PW) &&
           verifier.VerifyString(pw()) &&
           verifier.EndTable();
  }
};

struct Login_reqBuilder {
  typedef Login_req Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_id(flatbuffers::Offset<flatbuffers::String> id) {
    fbb_.AddOffset(Login_req::VT_ID, id);
  }
  void add_pw(flatbuffers::Offset<flatbuffers::String> pw) {
    fbb_.AddOffset(Login_req::VT_PW, pw);
  }
  explicit Login_reqBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  Login_reqBuilder &operator=(const Login_reqBuilder &);
  flatbuffers::Offset<Login_req> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Login_req>(end);
    return o;
  }
};

inline flatbuffers::Offset<Login_req> CreateLogin_req(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> id = 0,
    flatbuffers::Offset<flatbuffers::String> pw = 0) {
  Login_reqBuilder builder_(_fbb);
  builder_.add_pw(pw);
  builder_.add_id(id);
  return builder_.Finish();
}

inline flatbuffers::Offset<Login_req> CreateLogin_reqDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *id = nullptr,
    const char *pw = nullptr) {
  auto id__ = id ? _fbb.CreateString(id) : 0;
  auto pw__ = pw ? _fbb.CreateString(pw) : 0;
  return SamplePacket::CreateLogin_req(
      _fbb,
      id__,
      pw__);
}

inline bool VerifyAny(flatbuffers::Verifier &verifier, const void *obj, Any type) {
  switch (type) {
    case Any_NONE: {
      return true;
    }
    case Any_textREQ: {
      auto ptr = reinterpret_cast<const SamplePacket::textREQ *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Any_textACK: {
      auto ptr = reinterpret_cast<const SamplePacket::textACK *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return true;
  }
}

inline bool VerifyAnyVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (!values || !types) return !values && !types;
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyAny(
        verifier,  values->Get(i), types->GetEnum<Any>(i))) {
      return false;
    }
  }
  return true;
}

inline const SamplePacket::textREQ *GettextREQ(const void *buf) {
  return flatbuffers::GetRoot<SamplePacket::textREQ>(buf);
}

inline const SamplePacket::textREQ *GetSizePrefixedtextREQ(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<SamplePacket::textREQ>(buf);
}

inline bool VerifytextREQBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<SamplePacket::textREQ>(nullptr);
}

inline bool VerifySizePrefixedtextREQBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<SamplePacket::textREQ>(nullptr);
}

inline void FinishtextREQBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<SamplePacket::textREQ> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedtextREQBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<SamplePacket::textREQ> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace SamplePacket

#endif  // FLATBUFFERS_GENERATED_SAMPLEPACKET_SAMPLEPACKET_H_

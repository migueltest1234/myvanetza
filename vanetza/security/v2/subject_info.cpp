#include <vanetza/security/v2/subject_info.hpp>
#include <vanetza/security/v2/length_coding.hpp>

namespace vanetza
{
namespace security
{
namespace v2
{

size_t get_size(const SubjectInfo& sub)
{
    size_t size = sizeof(sub.subject_type);
    size += sub.subject_name.size();
    size += length_coding_size(sub.subject_name.size());
    return size;
}

void serialize(OutputArchive& ar, const SubjectInfo& sub)
{
    serialize(ar, sub.subject_type);
    size_t size = sub.subject_name.size();
    serialize_length(ar, size);
    for (auto& byte : sub.subject_name) {
        ar << byte;
    }
}

size_t deserialize(InputArchive& ar, SubjectInfo& sub)
{
    deserialize(ar, sub.subject_type);
    const std::uintmax_t size = deserialize_length(ar);
    for (uintmax_t c = 0; c < size; ++c) {
        uint8_t tmp;
        ar >> tmp;
        sub.subject_name.push_back(tmp);
    }
    return get_size(sub);
}

} // ns v2
} // ns security
} // ns vanetza

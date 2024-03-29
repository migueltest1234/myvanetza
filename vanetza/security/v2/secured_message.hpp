#ifndef SECURED_MESSAGE_HPP_MO3HBSXG
#define SECURED_MESSAGE_HPP_MO3HBSXG

#include <vanetza/common/its_aid.hpp>
#include <vanetza/security/v2/header_field.hpp>
#include <vanetza/security/v2/trailer_field.hpp>
#include <vanetza/security/v2/payload.hpp>
#include <cstdint>
#include <list>

namespace vanetza
{
namespace security
{
namespace v2
{

/// SecuredMessage as specified in TS 103 097 v1.2.1, section 5.1
struct SecuredMessage
{
    std::list<HeaderField> header_fields;
    std::list<TrailerField> trailer_fields;
    Payload payload;

    uint8_t protocol_version() const { return 2; }

    /**
     * Fetch pointer to first matching header field
     * \param type HeaderField has to match given type
     * \return matching HeaderField or nullptr
     */
    HeaderField* header_field(HeaderFieldType);

    /**
     * Fetch read-only pointer to first machting header field
     * \param type requested header field type
     * \return matching header field or nullptr
     */
    const HeaderField* header_field(HeaderFieldType type) const;

    /**
     * Fetch pointer to first matching trailer field
     * \param type TrailerField has to match given type
     * \return matching TrailerField or nullptr
     */
    TrailerField* trailer_field(TrailerFieldType);

    /**
     * Fetch read-only pointer of first matching trailer field
     * \param type request trailer field type
     * \return matching trailer field or nullptr
     */
    const TrailerField* trailer_field(TrailerFieldType type) const;

    template<HeaderFieldType T>
    typename header_field_type<T>::type* header_field()
    {
        using field_type = typename header_field_type<T>::type;
        HeaderField* field = header_field(T);
        return boost::get<field_type>(field);
    }

    template<HeaderFieldType T>
    const typename header_field_type<T>::type* header_field() const
    {
        using field_type = typename header_field_type<T>::type;
        const HeaderField* field = header_field(T);
        return boost::get<field_type>(field);
    }

    template<TrailerFieldType T>
    typename trailer_field_type<T>::type* trailer_field()
    {
        using field_type = typename trailer_field_type<T>::type;
        TrailerField* field = trailer_field(T);
        return boost::get<field_type>(field);
    }

    template<TrailerFieldType T>
    const typename trailer_field_type<T>::type* trailer_field() const
    {
        using field_type = typename trailer_field_type<T>::type;
        const TrailerField* field = trailer_field(T);
        return boost::get<field_type>(field);
    }
};

/**
 * \brief Calculates size of a SecuredMessage object
 * \return size_t containing the number of octets needed to serialize the object
 */
size_t get_size(const SecuredMessage&);

/**
 * \brief Serializes a SecuredMessage into a binary archive
 */
void serialize(OutputArchive& ar, const SecuredMessage& message);

/**
 * \brief Deserializes a SecuredMessage from a binary archive
 * \return size of deserialized SecuredMessage
 */
size_t deserialize(InputArchive& ar, SecuredMessage& message);

/**
 * \brief Create ByteBuffer equivalent of SecuredMessage suitable for signature creation
 *
 * ByteBuffer contains message's version, header_fields and payload.
 * Additionally, the length of trailer fields and the type of the signature is appended.
 *
 * \param message
 * \param trailer_fields only trailer fields up to signature will be included in byte buffer
 * \return serialized data fields relevant for signature creation
 */
ByteBuffer convert_for_signing(const SecuredMessage& message, const std::list<TrailerField>& trailer_fields);

/**
 * \brief Get ITS-AID from message
 * \param msg secured message object
 * \return found ITS-AID or 0
 */
ItsAid get_its_aid(const SecuredMessage& msg);

} // namespace v2
} // namespace security
} // namespace vanetza

#endif /* SECURED_MESSAGE_HPP_MO3HBSXG */

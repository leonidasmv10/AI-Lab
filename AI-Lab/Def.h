#pragma once
namespace Engine
{
#define TO_STRING( x ) #x

    //****************
    // CLASS_DECLARATION
    //****************
#define CLASS_DECLARATION( class_name )                                                      \
    public:                                                                                     \
        static const std::size_t type;                                                          \
        virtual bool IsClassType( const std::size_t class_type ) const override;                 \

    //****************
    // CLASS_DECLARATION
    //****************
#define CLASS_DEFINITION( parent_class, child_class )                                         \
    const std::size_t child_class::type = std::hash< std::string >()( TO_STRING( child_class ) ); \
    bool child_class::IsClassType( const std::size_t class_type ) const {                         \
            if ( class_type == child_class::type )                                                \
                return true;                                                                    \
            return parent_class::IsClassType( class_type );                                       \
    }
}
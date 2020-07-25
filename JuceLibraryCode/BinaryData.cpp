/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== power.svg ==================
static const unsigned char temp_binary_data_0[] =
"<svg id=\"Custom_Icon_SVGs\" data-name=\"Custom Icon SVGs\" xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 20 20\"><defs><style>.cls-1{fill:#141414;}</style></defs><path class=\"cls-1\" d=\"M14.34,3.26,13.29,5a6,6,0,1,1-6.44-.09l-1-1.69a8,8,0,1,0"
",8.54.08Z\"/><rect class=\"cls-1\" x=\"9.15\" y=\"2.02\" width=\"2\" height=\"8.01\"/></svg>";

const char* power_svg = (const char*) temp_binary_data_0;


const char* getNamedResource (const char* resourceNameUTF8, int& numBytes)
{
    unsigned int hash = 0;

    if (resourceNameUTF8 != nullptr)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0x32656c2a:  numBytes = 320; return power_svg;
        default: break;
    }

    numBytes = 0;
    return nullptr;
}

const char* namedResourceList[] =
{
    "power_svg"
};

const char* originalFilenames[] =
{
    "power.svg"
};

const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8)
{
    for (unsigned int i = 0; i < (sizeof (namedResourceList) / sizeof (namedResourceList[0])); ++i)
    {
        if (namedResourceList[i] == resourceNameUTF8)
            return originalFilenames[i];
    }

    return nullptr;
}

}

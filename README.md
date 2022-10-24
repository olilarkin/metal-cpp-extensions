# metal-cpp-extensions

C++ bindings into Apple's platform SDK to help with using Metal directly from C++. The majority of the code is from Apple, taken from their [Learn Metal with C++](https://developer.apple.com/metal/LearnMetalCPP.zip) example but with some things added by me. This will probably never be an exhaustive set of bindings, I just add what I need when I need them.

## Additions to Apple's code

* MTK::TextureLoader
    * only has the `MTL::Texture* newTexture( const NS::URL* URL, const NS::Dictionary* options, NS::Error** error );` method, and I haven't tested setting anything other than `nullptr` for the options.

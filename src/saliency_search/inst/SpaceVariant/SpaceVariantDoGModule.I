/*               -*- mode: c++ -*-

   DO NOT EDIT THIS FILE -- CHANGES WILL BE LOST!

   [Wed Dec 12 09:02:54 BRST 2012] This file was automatically generated by
   applying the script "./devscripts/extract_templates.tcl" to the template
   declarations in source file "src/SpaceVariant/SpaceVariantDoGModule.H"
   for types [byte, float]
*/
#ifndef INST_CLASS
#  define INST_CLASS
#endif
#ifdef INST_NAMESPACE
namespace INST_NAMESPACE {
#endif
template Image< promote_trait<byte, float>::TP> INST_CLASS transformDoG(const Image<byte>& ret_image, const ImageSet< promote_trait<byte, float>::TP>* const pyr_cache );
template Image< promote_trait< PixRGB<byte> , float>::TP> INST_CLASS transformDoG(const Image< PixRGB<byte> >& ret_image, const ImageSet< promote_trait< PixRGB<byte> , float>::TP>* const pyr_cache );
template Image< promote_trait<float, float>::TP> INST_CLASS transformDoG(const Image<float>& ret_image, const ImageSet< promote_trait<float, float>::TP>* const pyr_cache );
template Image< promote_trait< PixRGB<float> , float>::TP> INST_CLASS transformDoG(const Image< PixRGB<float> >& ret_image, const ImageSet< promote_trait< PixRGB<float> , float>::TP>* const pyr_cache );
template void INST_CLASS transformDoGPyramid(const Image<byte>& image, ImageSet< promote_trait<byte, float>::TP>& pyramid, const SVChanLevels& levels, const ImageSet< promote_trait<byte, float>::TP>* const pyr_cache );
template void INST_CLASS transformDoGPyramid(const Image< PixRGB<byte> >& image, ImageSet< promote_trait< PixRGB<byte> , float>::TP>& pyramid, const SVChanLevels& levels, const ImageSet< promote_trait< PixRGB<byte> , float>::TP>* const pyr_cache );
template void INST_CLASS transformDoGPyramid(const Image<float>& image, ImageSet< promote_trait<float, float>::TP>& pyramid, const SVChanLevels& levels, const ImageSet< promote_trait<float, float>::TP>* const pyr_cache );
template void INST_CLASS transformDoGPyramid(const Image< PixRGB<float> >& image, ImageSet< promote_trait< PixRGB<float> , float>::TP>& pyramid, const SVChanLevels& levels, const ImageSet< promote_trait< PixRGB<float> , float>::TP>* const pyr_cache );
#ifdef INST_NAMESPACE
}
#endif

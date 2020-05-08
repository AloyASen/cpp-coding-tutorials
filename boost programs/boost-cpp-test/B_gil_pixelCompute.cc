#include<iostream>
#include <boost/gil.hpp>
using namespace boost::gil;

void x_gradient(const gray8c_view_t& src, const gray8s_view_t& dst)
{
  assert(src.dimensions() == dst.dimensions());
  ...    // compute the gradient
}
void ComputeXGradientGray8(const unsigned char* src_pixels, ptrdiff_t src_row_bytes, int w, int h,
                           signed char* dst_pixels, ptrdiff_t dst_row_bytes)
{
  gray8c_view_t src = interleaved_view(w, h, (const gray8_pixel_t*)src_pixels,src_row_bytes);
  gray8s_view_t dst = interleaved_view(w, h, (     gray8s_pixel_t*)dst_pixels,dst_row_bytes);
  x_gradient(src,dst);
}
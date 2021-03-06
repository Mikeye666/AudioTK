/**
 * \file ButterworthFilter.cpp
 * For SIMD
 */

#include <simdpp/simd.h>

#include <ATK/EQ/SIMD/ButterworthFilter.h>

#include <ATK/EQ/ButterworthFilter.hxx>
#include <ATK/EQ/IIRFilter.h>
#include <ATK/EQ/SimpleIIRFilter.h>

#include <simdpp/dispatch/dispatcher.h>
#include <simdpp/dispatch/get_arch_gcc_builtin_cpu_supports.h>
#include <simdpp/dispatch/get_arch_raw_cpuid.h>
#include <simdpp/dispatch/get_arch_linux_cpuinfo.h>

#if SIMDPP_HAS_GET_ARCH_RAW_CPUID
# define SIMDPP_USER_ARCH_INFO ::simdpp::get_arch_raw_cpuid()
#elif SIMDPP_HAS_GET_ARCH_GCC_BUILTIN_CPU_SUPPORTS
# define SIMDPP_USER_ARCH_INFO ::simdpp::get_arch_gcc_builtin_cpu_supports()
#elif SIMDPP_HAS_GET_ARCH_LINUX_CPUINFO
# define SIMDPP_USER_ARCH_INFO ::simdpp::get_arch_linux_cpuinfo()
#else
# error "Unsupported platform"
#endif

namespace ATK
{
  template class ButterworthLowPassCoefficients<simdpp::float64<2> >;
  template class ButterworthHighPassCoefficients<simdpp::float64<2> >;
  template class ButterworthBandPassCoefficients<simdpp::float64<2> >;
  template class ButterworthBandStopCoefficients<simdpp::float64<2> >;

  template class ButterworthLowPassCoefficients<simdpp::float32<4> >;
  template class ButterworthLowPassCoefficients<simdpp::float64<4> >;
  template class ButterworthHighPassCoefficients<simdpp::float32<4> >;
  template class ButterworthHighPassCoefficients<simdpp::float64<4> >;
  template class ButterworthBandPassCoefficients<simdpp::float32<4> >;
  template class ButterworthBandPassCoefficients<simdpp::float64<4> >;
  template class ButterworthBandStopCoefficients<simdpp::float32<4> >;
  template class ButterworthBandStopCoefficients<simdpp::float64<4> >;
  
  template class ButterworthLowPassCoefficients<simdpp::float32<8> >;
  template class ButterworthLowPassCoefficients<simdpp::float64<8> >;
  template class ButterworthHighPassCoefficients<simdpp::float32<8> >;
  template class ButterworthHighPassCoefficients<simdpp::float64<8> >;
  template class ButterworthBandPassCoefficients<simdpp::float32<8> >;
  template class ButterworthBandPassCoefficients<simdpp::float64<8> >;
  template class ButterworthBandStopCoefficients<simdpp::float32<8> >;
  template class ButterworthBandStopCoefficients<simdpp::float64<8> >;

  template class SimpleIIRFilter<ButterworthLowPassCoefficients<simdpp::float64<2> > >;
  template class SimpleIIRFilter<ButterworthHighPassCoefficients<simdpp::float64<2> > >;
  template class SimpleIIRFilter<ButterworthBandPassCoefficients<simdpp::float64<2> > >;
  template class SimpleIIRFilter<ButterworthBandStopCoefficients<simdpp::float64<2> > >;

  template class SimpleIIRFilter<ButterworthLowPassCoefficients<simdpp::float32<4> > >;
  template class SimpleIIRFilter<ButterworthLowPassCoefficients<simdpp::float64<4> > >;
  template class SimpleIIRFilter<ButterworthHighPassCoefficients<simdpp::float32<4> > >;
  template class SimpleIIRFilter<ButterworthHighPassCoefficients<simdpp::float64<4> > >;
  template class SimpleIIRFilter<ButterworthBandPassCoefficients<simdpp::float32<4> > >;
  template class SimpleIIRFilter<ButterworthBandPassCoefficients<simdpp::float64<4> > >;
  template class SimpleIIRFilter<ButterworthBandStopCoefficients<simdpp::float32<4> > >;
  template class SimpleIIRFilter<ButterworthBandStopCoefficients<simdpp::float64<4> > >;
  
  template class SimpleIIRFilter<ButterworthLowPassCoefficients<simdpp::float32<8> > >;
  template class SimpleIIRFilter<ButterworthLowPassCoefficients<simdpp::float64<8> > >;
  template class SimpleIIRFilter<ButterworthHighPassCoefficients<simdpp::float32<8> > >;
  template class SimpleIIRFilter<ButterworthHighPassCoefficients<simdpp::float64<8> > >;
  template class SimpleIIRFilter<ButterworthBandPassCoefficients<simdpp::float32<8> > >;
  template class SimpleIIRFilter<ButterworthBandPassCoefficients<simdpp::float64<8> > >;
  template class SimpleIIRFilter<ButterworthBandStopCoefficients<simdpp::float32<8> > >;
  template class SimpleIIRFilter<ButterworthBandStopCoefficients<simdpp::float64<8> > >;

  template class IIRTDF2Filter<ButterworthLowPassCoefficients<simdpp::float64<2> > >;
  template class IIRTDF2Filter<ButterworthHighPassCoefficients<simdpp::float64<2> > >;
  template class IIRTDF2Filter<ButterworthBandPassCoefficients<simdpp::float64<2> > >;
  template class IIRTDF2Filter<ButterworthBandStopCoefficients<simdpp::float64<2> > >;

  template class IIRTDF2Filter<ButterworthLowPassCoefficients<simdpp::float32<4> > >;
  template class IIRTDF2Filter<ButterworthLowPassCoefficients<simdpp::float64<4> > >;
  template class IIRTDF2Filter<ButterworthHighPassCoefficients<simdpp::float32<4> > >;
  template class IIRTDF2Filter<ButterworthHighPassCoefficients<simdpp::float64<4> > >;
  template class IIRTDF2Filter<ButterworthBandPassCoefficients<simdpp::float32<4> > >;
  template class IIRTDF2Filter<ButterworthBandPassCoefficients<simdpp::float64<4> > >;
  template class IIRTDF2Filter<ButterworthBandStopCoefficients<simdpp::float32<4> > >;
  template class IIRTDF2Filter<ButterworthBandStopCoefficients<simdpp::float64<4> > >;
  
  template class IIRTDF2Filter<ButterworthLowPassCoefficients<simdpp::float32<8> > >;
  template class IIRTDF2Filter<ButterworthLowPassCoefficients<simdpp::float64<8> > >;
  template class IIRTDF2Filter<ButterworthHighPassCoefficients<simdpp::float32<8> > >;
  template class IIRTDF2Filter<ButterworthHighPassCoefficients<simdpp::float64<8> > >;
  template class IIRTDF2Filter<ButterworthBandPassCoefficients<simdpp::float32<8> > >;
  template class IIRTDF2Filter<ButterworthBandPassCoefficients<simdpp::float64<8> > >;
  template class IIRTDF2Filter<ButterworthBandStopCoefficients<simdpp::float32<8> > >;
  template class IIRTDF2Filter<ButterworthBandStopCoefficients<simdpp::float64<8> > >;

  namespace SIMDPP_ARCH_NAMESPACE
  {
    template<typename DataType, std::size_t VL>
    std::unique_ptr<BaseFilter> createLowPassButterworthFilter(std::size_t nb_channels)
    {
      return std::unique_ptr<BaseFilter>(new SimpleIIRFilter<ButterworthLowPassCoefficients<typename SIMDTypeTraits<DataType>::template SIMDType<VL> > >(nb_channels));
    }
    template<typename DataType, std::size_t VL>
    std::unique_ptr<BaseFilter> createHighPassButterworthFilter(std::size_t nb_channels)
    {
      return std::unique_ptr<BaseFilter>(new SimpleIIRFilter<ButterworthHighPassCoefficients<typename SIMDTypeTraits<DataType>::template SIMDType<VL> > >(nb_channels));
    }
    template<typename DataType, std::size_t VL>
    std::unique_ptr<BaseFilter> createBandPassButterworthFilter(std::size_t nb_channels)
    {
      return std::unique_ptr<BaseFilter>(new SimpleIIRFilter<ButterworthBandPassCoefficients<typename SIMDTypeTraits<DataType>::template SIMDType<VL> > >(nb_channels));
    }
    template<typename DataType, std::size_t VL>
    std::unique_ptr<BaseFilter> createBandStopButterworthFilter(std::size_t nb_channels)
    {
      return std::unique_ptr<BaseFilter>(new SimpleIIRFilter<ButterworthBandStopCoefficients<typename SIMDTypeTraits<DataType>::template SIMDType<VL> > >(nb_channels));
    }
    template<typename DataType, std::size_t VL>
    std::unique_ptr<BaseFilter> createLowPassButterworthTDF2Filter(std::size_t nb_channels)
    {
      return std::unique_ptr<BaseFilter>(new IIRTDF2Filter<ButterworthLowPassCoefficients<typename SIMDTypeTraits<DataType>::template SIMDType<VL> > >(nb_channels));
    }
    template<typename DataType, std::size_t VL>
    std::unique_ptr<BaseFilter> createHighPassButterworthTDF2Filter(std::size_t nb_channels)
    {
      return std::unique_ptr<BaseFilter>(new IIRTDF2Filter<ButterworthHighPassCoefficients<typename SIMDTypeTraits<DataType>::template SIMDType<VL> > >(nb_channels));
    }
    template<typename DataType, std::size_t VL>
    std::unique_ptr<BaseFilter> createBandPassButterworthTDF2Filter(std::size_t nb_channels)
    {
      return std::unique_ptr<BaseFilter>(new IIRTDF2Filter<ButterworthBandPassCoefficients<typename SIMDTypeTraits<DataType>::template SIMDType<VL> > >(nb_channels));
    }
    template<typename DataType, std::size_t VL>
    std::unique_ptr<BaseFilter> createBandStopButterworthTDF2Filter(std::size_t nb_channels)
    {
      return std::unique_ptr<BaseFilter>(new IIRTDF2Filter<ButterworthBandStopCoefficients<typename SIMDTypeTraits<DataType>::template SIMDType<VL> > >(nb_channels));
    }
  }
  
  SIMDPP_MAKE_DISPATCHER((template<typename DataType, std::size_t VL>) (<DataType, VL>) (std::unique_ptr<BaseFilter>) (createLowPassButterworthFilter) ((std::size_t) nb_channels))
  SIMDPP_MAKE_DISPATCHER((template<typename DataType, std::size_t VL>) (<DataType, VL>) (std::unique_ptr<BaseFilter>) (createHighPassButterworthFilter) ((std::size_t) nb_channels))
  SIMDPP_MAKE_DISPATCHER((template<typename DataType, std::size_t VL>) (<DataType, VL>) (std::unique_ptr<BaseFilter>) (createBandPassButterworthFilter) ((std::size_t) nb_channels))
  SIMDPP_MAKE_DISPATCHER((template<typename DataType, std::size_t VL>) (<DataType, VL>) (std::unique_ptr<BaseFilter>) (createBandStopButterworthFilter) ((std::size_t) nb_channels))
  SIMDPP_MAKE_DISPATCHER((template<typename DataType, std::size_t VL>) (<DataType, VL>) (std::unique_ptr<BaseFilter>) (createLowPassButterworthTDF2Filter) ((std::size_t) nb_channels))
  SIMDPP_MAKE_DISPATCHER((template<typename DataType, std::size_t VL>) (<DataType, VL>) (std::unique_ptr<BaseFilter>) (createHighPassButterworthTDF2Filter) ((std::size_t) nb_channels))
  SIMDPP_MAKE_DISPATCHER((template<typename DataType, std::size_t VL>) (<DataType, VL>) (std::unique_ptr<BaseFilter>) (createBandPassButterworthTDF2Filter) ((std::size_t) nb_channels))
  SIMDPP_MAKE_DISPATCHER((template<typename DataType, std::size_t VL>) (<DataType, VL>) (std::unique_ptr<BaseFilter>) (createBandStopButterworthTDF2Filter) ((std::size_t) nb_channels))
  
  SIMDPP_INSTANTIATE_DISPATCHER(
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createLowPassButterworthFilter<double, 2>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createHighPassButterworthFilter<double, 2>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createBandPassButterworthFilter<double, 2>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createBandStopButterworthFilter<double, 2>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createLowPassButterworthTDF2Filter<double, 2>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createHighPassButterworthTDF2Filter<double, 2>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createBandPassButterworthTDF2Filter<double, 2>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createBandStopButterworthTDF2Filter<double, 2>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createLowPassButterworthFilter<float, 4>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createLowPassButterworthFilter<double, 4>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createLowPassButterworthFilter<float, 8>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createLowPassButterworthFilter<double, 8>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createHighPassButterworthFilter<float, 4>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createHighPassButterworthFilter<double, 4>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createHighPassButterworthFilter<float, 8>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createHighPassButterworthFilter<double, 8>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createBandPassButterworthFilter<float, 4>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createBandPassButterworthFilter<double, 4>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createBandPassButterworthFilter<float, 8>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createBandPassButterworthFilter<double, 8>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createBandStopButterworthFilter<float, 4>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createBandStopButterworthFilter<double, 4>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createBandStopButterworthFilter<float, 8>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createBandStopButterworthFilter<double, 8>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createLowPassButterworthTDF2Filter<float, 4>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createLowPassButterworthTDF2Filter<double, 4>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createLowPassButterworthTDF2Filter<float, 8>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createLowPassButterworthTDF2Filter<double, 8>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createHighPassButterworthTDF2Filter<float, 4>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createHighPassButterworthTDF2Filter<double, 4>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createHighPassButterworthTDF2Filter<float, 8>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createHighPassButterworthTDF2Filter<double, 8>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createBandPassButterworthTDF2Filter<float, 4>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createBandPassButterworthTDF2Filter<double, 4>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createBandPassButterworthTDF2Filter<float, 8>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createBandPassButterworthTDF2Filter<double, 8>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createBandStopButterworthTDF2Filter<float, 4>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createBandStopButterworthTDF2Filter<double, 4>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createBandStopButterworthTDF2Filter<float, 8>(std::size_t)),
    (template ATK_EQSIMD_EXPORT std::unique_ptr<BaseFilter> createBandStopButterworthTDF2Filter<double, 8>(std::size_t)));
}

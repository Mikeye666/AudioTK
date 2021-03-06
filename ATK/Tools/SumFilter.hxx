/**
 * \file SumFilter.hxx
 */

#include <ATK/Tools/SumFilter.h>

#include <cstring>

namespace ATK
{
  template<typename DataType_>
  SumFilter<DataType_>::SumFilter(std::size_t nb_output_channels, std::size_t summed_channels)
  :Parent(summed_channels * nb_output_channels, nb_output_channels), summed_channels(summed_channels)
  {
  }
  
  template<typename DataType_>
  SumFilter<DataType_>::~SumFilter()
  {
  }

  template<typename DataType_>
  void SumFilter<DataType_>::process_impl(std::size_t size) const
  {
    assert(nb_input_ports == summed_channels * nb_output_ports);

    for (unsigned int channel = 0; channel < nb_output_ports; ++channel)
    {
      const DataType* ATK_RESTRICT input = converted_inputs[summed_channels * channel];
      DataType* ATK_RESTRICT output = outputs[channel];
      std::memcpy(output, input, size * sizeof(DataType_));
      
      for(std::size_t summed_channel = 1; summed_channel < summed_channels; ++summed_channel)
      {
        const DataType* ATK_RESTRICT input = converted_inputs[summed_channels * channel + summed_channel];
        for (std::size_t i = 0; i < size; ++i)
        {
          output[i] = output[i] + input[i];
        }
      }
    }
  }
}

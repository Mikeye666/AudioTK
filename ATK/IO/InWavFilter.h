/**
 * \file InWavFilter.h
 */

#ifndef ATK_IO_INWAVFILTER_H
#define ATK_IO_INWAVFILTER_H

#include <fstream>
#include <string>

#include <ATK/Core/TypedBaseFilter.h>

#include <ATK/IO/config.h>
#include <ATK/IO/WavStruct.h>

namespace ATK
{
  /// Simple wav source, not as robust as the SndFile version
  template<typename DataType_>
  class ATK_IO_EXPORT InWavFilter final : public TypedBaseFilter<DataType_>
  {
  public:
    /// Simplify parent calls
    typedef TypedBaseFilter<DataType_> Parent;
    using typename Parent::DataType;
    using Parent::outputs;
    using Parent::output_sampling_rate;
    using Parent::set_output_sampling_rate;
    using Parent::set_nb_output_ports;

  private:
    mutable std::vector<std::vector<DataType> > temp_arrays;
    mutable std::ifstream wavstream;
    std::string filename;
    WavHeader header;
    WavFormat format;
    WavData data;
    std::streamoff offset;
        
    void read_from_file(std::size_t size) const;

  public:
    /*!
    * @brief Constructor
    * @param filename is the name of the input file
    */
    InWavFilter(const std::string& filename);
  protected:
    void process_impl(std::size_t size) const final;
  };
}
#endif

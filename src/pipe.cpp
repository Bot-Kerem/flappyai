#include "pipe.h"

#include <stdlib.h>

#include <iostream>

Pipe::Pipe(){
  PipeSpace =  std::min(std::max((float)((double) rand() / (RAND_MAX)), MinPipeSpace), MaxPipeSpace);
  Height =  std::min(std::max((float)((double) rand() / (RAND_MAX)) * 2, MinHeight), 2.0f - (PipeSpace + MinHeight));
}

Pipe::~Pipe() = default;

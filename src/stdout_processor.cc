#include "stdout_processor.h"

StdoutProcessor::StdoutProcessor() {
    SetTypeName(NAME_OF_THIS); // Provide JANA with this class's name
}

void StdoutProcessor::Init() {
}

void StdoutProcessor::Process(const std::shared_ptr<const JEvent> &event) {

}

void StdoutProcessor::Finish() {

}


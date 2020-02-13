
#include "random_source.h"

/// There are two different ways of creating JEventSources --
/// either specifying them directly,
RandomSource::RandomSource(JApplication* app) : JEventSource("random", app) {}

/// Open is called exactly once before the . It is important that
void RandomSource::Open() {
    m_generator = new std::mt19937(m_seed);
}

/// Calls to GetEvent are synchronized with each other, which means they can
/// read and write state on the JEventSource without causing race conditions.
void RandomSource::GetEvent(std::shared_ptr <JEvent>) {

}

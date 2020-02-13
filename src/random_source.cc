
#include "random_source.h"
#include "hit.h"

#include <JANA/JApplication.h>
#include <JANA/JEvent.h>


/// There are two different ways of creating JEventSources
/// 1. Creating them manually and registering them with the JApplication
/// 2. Creating a corresponding JEventSourceGenerator and registering that instead
///    If you have a list of files as command line args, JANA will use the JEventSourceGenerator
///    to find the most appropriate JEventSource corresponding to that filename, instantiate and register it.
///    For this to work, the JEventSource constructor has to have the following constructor arguments:

RandomSource::RandomSource(std::string resource_name, JApplication* app) : JEventSource(resource_name, app) {
    SetTypeName(NAME_OF_THIS); // Provide JANA with class name
}

/// Open is called exactly once when processing begins.
void RandomSource::Open() {

    // Get random seed from configuration parameters
    GetApplication()->SetDefaultParameter("sample_plugin:random_seed", m_seed, "Seed for RandomSource");
    m_generator = new std::mt19937(m_seed);

    // If you were opening a file, you would get the filename via:
    // std::string resource_name = GetResourceName();
}

/// Calls to GetEvent are synchronized with each other, which means they can
/// read and write state on the JEventSource without causing race conditions.
void RandomSource::GetEvent(std::shared_ptr <JEvent> event) {

    static size_t current_event_number = 1;

    // Configure event and run numbers
    event->SetRunNumber(22);
    event->SetEventNumber(current_event_number++);

    // Insert whatever data was read into the event
    std::vector<Hit*> hits;
    hits.push_back(new Hit(0,0,1.0,0));
    hits.push_back(new Hit(0,1,1.0,0));
    hits.push_back(new Hit(1,0,1.0,0));
    hits.push_back(new Hit(1,1,1.0,0));
    event->Insert(hits);

    // This will emit an infinite stream of events.
    // If you are reading a file of events and have reached the end, you can terminate
    // the stream like this:
    //throw RETURN_STATUS::kNO_MORE_EVENTS;

    // Similarly, if you are streaming events and there are no new events in the message queue,
    // you can tell JANA that GetEvent() was temporarily unsuccessful like this:
    //throw RETURN_STATUS::kBUSY;
}



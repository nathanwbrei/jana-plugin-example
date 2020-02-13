
#include "catch.hpp"

#include <JANA/JEvent.h>

#include "hit.h"
#include "shower_factory.h"

TEST_CASE("ShowerFactoryTests") {

    // This is our "system-under-test"
    auto shower_factory = new ShowerFactory;

    // Create a new event object and attach the factory to our event
    auto event = std::make_shared<JEvent>();
    auto factory_set = new JFactorySet;
    factory_set->Add(shower_factory);
    event->SetFactorySet(factory_set);

    // Feed some input data into the event object
    std::vector<Hit*> hits;
    hits.push_back(new Hit(0, 0, 1.5, 1.0));
    hits.push_back(new Hit(0, 1, 1.7, 1.1));
    event->Insert(hits);

    // The JEvent will call Init, Process, and ChangeRun as needed for us
    // We could also call them ourselves directly. However, we won't have access
    // to the private internal state of the JFactory parent, which includes all
    // of the data we generated.
    auto results = event->Get<Shower>();

    // Assert something based on results calculated or changes to factory members
    REQUIRE(true == true);

}

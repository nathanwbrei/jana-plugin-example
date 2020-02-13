#include "catch.hpp"

#include <JANA/JApplication.h>
#include <JANA/JFactoryGenerator.h>

#include <stdout_processor.h>
#include <shower_factory.h>
#include <random_source.h>


// This is where you can assemble various components and verify that when put together, they
// do what you'd expect. This means you can skip the laborious mixing and matching of plugins and configurations,
// and have everything run automatically inside one executable.

TEST_CASE("IntegrationTests") {

    auto app = new JApplication;
    auto source = new RandomSource("random", app);
    auto processor = new StdoutProcessor;

    // Register components
    app->Add(source);
    app->Add(processor);
    app->Add(new JFactoryGeneratorT<ShowerFactory>());

    // Tell JANA to only emit some number of events
    app->SetParameterValue("nevents", 10);

    // Run everything, blocking until finished
    app->Run();

    // Make assertions about the data
    REQUIRE(app->GetNeventsProcessed() == 10);

}



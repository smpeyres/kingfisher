#include "kingfisherApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
kingfisherApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

kingfisherApp::kingfisherApp(InputParameters parameters) : MooseApp(parameters)
{
  kingfisherApp::registerAll(_factory, _action_factory, _syntax);
}

kingfisherApp::~kingfisherApp() {}

void
kingfisherApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<kingfisherApp>(f, af, s);
  Registry::registerObjectsTo(f, {"kingfisherApp"});
  Registry::registerActionsTo(af, {"kingfisherApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
kingfisherApp::registerApps()
{
  registerApp(kingfisherApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
kingfisherApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  kingfisherApp::registerAll(f, af, s);
}
extern "C" void
kingfisherApp__registerApps()
{
  kingfisherApp::registerApps();
}

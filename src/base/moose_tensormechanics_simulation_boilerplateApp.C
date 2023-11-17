#include "moose_tensormechanics_simulation_boilerplateApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
moose_tensormechanics_simulation_boilerplateApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

moose_tensormechanics_simulation_boilerplateApp::moose_tensormechanics_simulation_boilerplateApp(InputParameters parameters) : MooseApp(parameters)
{
  moose_tensormechanics_simulation_boilerplateApp::registerAll(_factory, _action_factory, _syntax);
}

moose_tensormechanics_simulation_boilerplateApp::~moose_tensormechanics_simulation_boilerplateApp() {}

void 
moose_tensormechanics_simulation_boilerplateApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<moose_tensormechanics_simulation_boilerplateApp>(f, af, s);
  Registry::registerObjectsTo(f, {"moose_tensormechanics_simulation_boilerplateApp"});
  Registry::registerActionsTo(af, {"moose_tensormechanics_simulation_boilerplateApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
moose_tensormechanics_simulation_boilerplateApp::registerApps()
{
  registerApp(moose_tensormechanics_simulation_boilerplateApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
moose_tensormechanics_simulation_boilerplateApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  moose_tensormechanics_simulation_boilerplateApp::registerAll(f, af, s);
}
extern "C" void
moose_tensormechanics_simulation_boilerplateApp__registerApps()
{
  moose_tensormechanics_simulation_boilerplateApp::registerApps();
}

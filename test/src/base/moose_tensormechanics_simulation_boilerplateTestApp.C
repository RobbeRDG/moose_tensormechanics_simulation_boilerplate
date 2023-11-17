//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "moose_tensormechanics_simulation_boilerplateTestApp.h"
#include "moose_tensormechanics_simulation_boilerplateApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
moose_tensormechanics_simulation_boilerplateTestApp::validParams()
{
  InputParameters params = moose_tensormechanics_simulation_boilerplateApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

moose_tensormechanics_simulation_boilerplateTestApp::moose_tensormechanics_simulation_boilerplateTestApp(InputParameters parameters) : MooseApp(parameters)
{
  moose_tensormechanics_simulation_boilerplateTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

moose_tensormechanics_simulation_boilerplateTestApp::~moose_tensormechanics_simulation_boilerplateTestApp() {}

void
moose_tensormechanics_simulation_boilerplateTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  moose_tensormechanics_simulation_boilerplateApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"moose_tensormechanics_simulation_boilerplateTestApp"});
    Registry::registerActionsTo(af, {"moose_tensormechanics_simulation_boilerplateTestApp"});
  }
}

void
moose_tensormechanics_simulation_boilerplateTestApp::registerApps()
{
  registerApp(moose_tensormechanics_simulation_boilerplateApp);
  registerApp(moose_tensormechanics_simulation_boilerplateTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
moose_tensormechanics_simulation_boilerplateTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  moose_tensormechanics_simulation_boilerplateTestApp::registerAll(f, af, s);
}
extern "C" void
moose_tensormechanics_simulation_boilerplateTestApp__registerApps()
{
  moose_tensormechanics_simulation_boilerplateTestApp::registerApps();
}

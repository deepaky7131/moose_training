#include "frogApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<frogApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

frogApp::frogApp(InputParameters parameters) : MooseApp(parameters)
{
  frogApp::registerAll(_factory, _action_factory, _syntax);
}

frogApp::~frogApp() {}

void
frogApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"frogApp"});
  Registry::registerActionsTo(af, {"frogApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
frogApp::registerApps()
{
  registerApp(frogApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
frogApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  frogApp::registerAll(f, af, s);
}
extern "C" void
frogApp__registerApps()
{
  frogApp::registerApps();
}

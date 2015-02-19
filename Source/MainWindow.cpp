/*
  ==============================================================================

    This file was auto-generated by the Jucer!

    It contains the basic outline for a simple desktop window.

  ==============================================================================
*/

#include "MainWindow.h"
#include "AudioManager.h"
#include "PVMainComponent.h"

//==============================================================================
MainAppWindow::MainAppWindow()
    : DocumentWindow (JUCEApplication::getInstance()->getApplicationName(),
                      Colours::lightgrey,
                      DocumentWindow::allButtons)
{
	/** Start the audio side of things */
	AudioManager::getInstance();

	setResizeLimits( 620, 400, 8192, 8192 );
	setResizable( true, false );
	setContentOwned( new PVMainComponent, false );
    centreWithSize (620, 400);
    setVisible (true);
}

MainAppWindow::~MainAppWindow()
{
	AudioManager::deleteInstance();
	clearContentComponent();
}

void MainAppWindow::closeButtonPressed()
{
    JUCEApplication::getInstance()->systemRequestedQuit();
}
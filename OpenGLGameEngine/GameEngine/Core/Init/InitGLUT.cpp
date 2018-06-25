#include "InitGLUT.h"

using namespace GameEngine::Core;
using namespace GameEngine::Core::Init;

IListener* InitGLUT::listener = NULL;
WindowInfo InitGLUT::windowInfomation;

void InitGLUT::Init(const WindowInfo& windowInfo, const ContextInfo& contextInfo, const FramebufferInfo& framebufferInfo)
{
	int fakeargc = 1;
	char* fakeargv[] = { (char*)"fake", NULL };
	glutInit(&fakeargc, fakeargv);

	if (contextInfo.core)
	{
		glutInitContextVersion(contextInfo.majorVersion, contextInfo.minorVersion);
		glutInitContextProfile(GLUT_CORE_PROFILE);
	}
	else
		glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	windowInfomation = windowInfo;
	glutInitDisplayMode(framebufferInfo.flags);
	glutInitWindowPosition(windowInfo.posX, windowInfo.posY);
	glutInitWindowSize(windowInfo.width, windowInfo.height);
	glutCreateWindow(windowInfo.name.c_str());

	std::cout << "GLUT:initialized" << std::endl;
	glEnable(GL_DEBUG_OUTPUT);

	InitGLEW::Init();
	glDebugMessageCallback((GLDEBUGPROC)DebugOutput::DebugCallback, NULL);
	glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE);

	glutIdleFunc(IdleCallback);
	glutCloseFunc(CloseCallback);
	glutDisplayFunc(DisplayCallback);
	glutReshapeFunc(ReshapeCallback);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	PrintOpenGLInfo(windowInfo, contextInfo);
}

void InitGLUT::Run()
{
	std::cout << "GLUT:\t Start Running " << std::endl;
	glutMainLoop();
}

void InitGLUT::Close()
{
	std::cout << "GLUT:\t Finished" << std::endl;
	glutLeaveMainLoop();
}

void InitGLUT::IdleCallback()
{
	glutPostRedisplay();
}

void InitGLUT::DisplayCallback()
{
	if (listener)
	{
		listener->NotifyBeginFrame();
		listener->NotifyDisplayFrame();

		glutSwapBuffers();

		listener->NotifyEndFrame();
	}
}

void InitGLUT::ReshapeCallback(int width, int height)
{
	if (windowInfomation.isReshapable)
	{
		if (listener)
			listener->NotifyReshape(width, height, windowInfomation.width, windowInfomation.height);

		windowInfomation.width = width;
		windowInfomation.height = height;
	}
}

void InitGLUT::CloseCallback()
{
	Close();
}

void InitGLUT::SetListener(IListener*& iListener)
{
	listener = iListener;
}

void InitGLUT::EnterFullscreen()
{
	glutFullScreen();
}

void InitGLUT::ExitFullscreen()
{
	glutLeaveFullScreen();
}


void InitGLUT::PrintOpenGLInfo(const WindowInfo& windowInfo, const ContextInfo& context)
{
	const unsigned char* renderer = glGetString(GL_RENDERER);
	const unsigned char* vendor = glGetString(GL_VENDOR);
	const unsigned char* version = glGetString(GL_VERSION);

	std::cout << "*******************************" << std::endl;
	std::cout << "GLUT:Initialize" << std::endl;
	std::cout << "GLUT:\tVendor : " << vendor << std::endl;
	std::cout << "GLUT:\tRenderer : " << renderer << std::endl;
	std::cout << "GLUT:\tOpenGL version : " << version << std::endl;
}
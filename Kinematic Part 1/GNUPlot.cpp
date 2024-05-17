#include "GNUPlot.h"

#include <fstream>
#include <iostream>
#include <string>


void GNUPlot::AddDataPoints()
{
	m_GNUPlotFile << "$PlotData << END" << std::endl;

	for (Point pt : m_points)
	{
		m_GNUPlotFile << pt.X() << "  " << pt.Y() << std::endl;
	}
	m_GNUPlotFile << "END" << std::endl;

	if (m_points2.size() > 0)
	{
		m_GNUPlotFile << "$PlotData2 << END" << std::endl;

		for (Point pt : m_points2)
		{
			m_GNUPlotFile << pt.X() << "  " << pt.Y() << std::endl;
		}
		m_GNUPlotFile << "END" << std::endl;
	}

	AddBlockData();
}

void GNUPlot::AddPlotCommand()
{
	m_GNUPlotFile << "plot ";

	if (m_points2.size() > 0)
	{
		m_GNUPlotFile << "$PlotData2 with points pt 7 ps 4 lc \"0x996633\", ";
	}

	m_GNUPlotFile << "$PlotData with linespoints pt 7 ps 2 lc \"0x0000aa\"";

	AppendBlockPlots();

	m_GNUPlotFile << std::endl;
}

void GNUPlot::AddBlockData()
{
	int iBlock = 0;
	for (Block block : m_blocks)
	{
		m_GNUPlotFile << "$Block" << iBlock << " << END" << std::endl;

		m_GNUPlotFile << block.X()                     << "   " << block.Y()                  << std::endl;
		m_GNUPlotFile << block.X()                     << "   " << block.Y() + block.Height() << std::endl;
		m_GNUPlotFile << block.X() + block.Width()     << "   " << block.Y() + block.Height() << std::endl;
		m_GNUPlotFile << block.X() + block.Width()     << "   " << block.Y()                  << std::endl;
		m_GNUPlotFile << block.X()                     << "   " << block.Y()                  << std::endl;

		m_GNUPlotFile << "END" << std::endl;

		++iBlock;
	}
}

void GNUPlot::AppendBlockPlots()
{
	int iBlock = 0;
	for (Block block : m_blocks)
	{
		std::string color = "0xaa0000";
		if (block.Y() <= 0.0)
			color = "0x00aa00";
		m_GNUPlotFile << ", $Block" << iBlock++ << " with filledcurves lc \"" << color << "\"";
	}
}

void GNUPlot::AddOptions()
{
	m_GNUPlotFile << "set key off" << std::endl;
}

void GNUPlot::Callgnuplot()
{

#ifdef _WIN32
	system("start gnuplot -persist GNUPlotFile.gnu");
#else
	m_GNUPlotFile << "pause -1 \"Hit any key to exit\"" << std::endl;
	system("/Applications/Gnuplot.app/Contents/Resources/bin/gnuplot-run.sh GNUPlotFile.gnu");
#endif
	m_GNUPlotFile.close();
}

void GNUPlot::GenerateAndDisplayPlotFile()
{
	AddDataPoints();

	AddOptions();

	AddPlotCommand();

	Callgnuplot();
}

GNUPlot::GNUPlot()
{
	m_GNUPlotFile.open("GNUPlotFile.gnu");
}

void GNUPlot::CreatePlot()
{
	GenerateAndDisplayPlotFile();
}

void GNUPlot::AddBlock(double xLocation, double yLocation, double height, double width)
{
	Block newBlock(xLocation, yLocation, height, width);
	m_blocks.push_back( newBlock );
}

void GNUPlot::AddPoint(double x, double y)
{
	Point newPoint(x, y);
	m_points.push_back(newPoint);
}

void GNUPlot::AddPoint2(double x, double y)
{
	Point newPoint(x, y);
	m_points2.push_back(newPoint);
}

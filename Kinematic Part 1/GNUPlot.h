#pragma once

#include <vector>
#include <fstream>
#include <iostream>

// Class to manage 2D point data
class Point
{
private:
	double m_x;
	double m_y;

public:
	Point() { m_x = 0.0; m_y = 0.0; }
	Point( double x, double y) { m_x = x; m_y = y; }
	double X() { return m_x; }
	double Y() { return m_y; }
};

class Block
{
private:
	double m_xLocation;
	double m_yLocation;
	double m_height;
	double m_width;

public:
	Block(double xLocation, double yLocation, double height, double width)
	{
		m_xLocation = xLocation;
		m_yLocation = yLocation;
		m_height    = height;
		m_width     = width;
	}

	double X() { return m_xLocation; }
	double Y() { return m_yLocation; }
	double Height() { return m_height; }
	double Width() { return m_width; }
};

class GNUPlot
{
private:
	// Output stream for the GNU plot file
	std::ofstream m_GNUPlotFile;

	// The data points to be plotted
	std::vector<Point> m_points;

	// The data points to be plotted for second plot
	std::vector<Point> m_points2;

	// Vector of blocks (filled rectangles) to plot
	std::vector<Block> m_blocks;

	// Adds the data points to the GNU plot file
	// This must be called before AddPlotCommand().
	void AddDataPoints();

	// Adds the block data points to the GNU plot file
	// This must be called before AddPlotCommand().
	void AppendBlockPlots();

	// Adds any options (e.g., hide data legend) to the GNU plot file.
	// This must be called before AddPlotCommand().
	void AddOptions();

	// Adds the plot command to the GNU data file
	void AddPlotCommand();

	// Appends the block plot commands to the plot command.
	// This must be called after AddPlotCommand().
	void AddBlockData();

	// Uses "gnuplot" to process and display the generated GNU plot file.
	// Note - this command closes the plot file.
	void Callgnuplot();

	// Generates and displays the GNU plot file
	void GenerateAndDisplayPlotFile();

	
public:
	// Default constructor.
	// This opens the GNU plot file for writing.
	GNUPlot();

	// Adds a data point to the list to be plotted.
	void AddPoint(double x, double y);

	// Adds a data point to the second list to be plotted.
	void AddPoint2(double x, double y);

	// Adds a block at the given location with the given dimensions.
	void AddBlock(double xLocation, double yLocation, double height, double width);

	// Generates and displays the GNU plot file
	// The output file is closed with this command meaning
	// no more data can be added to the plot.
	void CreatePlot();
};


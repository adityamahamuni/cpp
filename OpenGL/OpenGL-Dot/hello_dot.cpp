// In this tutorial we will see the usage of vertex buffer objects(VBOs) for the first time.
// As the name implies, they are used to store vertices.
// The objects that exist in the 3D world you are trying to visualize, be it monsters, castles or a simple revolving cube, 
// are always built by connecting together a group of vertices.VBOs are the most efficient way to load vertices into the GPU.
// They are buffers that can be stored in video memoryand provide the shortest access time to the GPU so they are definitely recommended.

#include<GL/glew.h>
#include <GLFW/glfw3.h>
#include<iostream>

#include "math_3d.h"

int main() {

	// Here we initialize GLEW and check for any errors. This must be done after GLUT has been initialized.
	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}

	// We create an array of one Vector3f structures (this type is defined in math_3d.h) and initialize XYZ to be zero. 
	// This will make the dot appear at the middle of the screen.
	Vector3f Vertices[1];
	Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);

	// We allocate a GLuint in the global part of the program to store the handle of the vertex buffer object. 
	// You will see later that most (if not all) OpenGL objects are accessed via a variable of GLuint type.
	GLuint VBO;

	// OpenGL defines several glGen* functions for generating objects of various types. 
	// They often take two parameters - the first one specifies the number of objects you want to create and 
	// the second is the address of an array of GLuints to store the handles that the driver allocates 
	// for you (make sure the array is large enough to handle your request!). 
	// Future calls to this function will not generate the same object handles unless you delete them first with glDeleteBuffers. 
	// Note that at this point you don't specify what you intend to do with the buffers so they can be regarded as "generic". 
	// This is the job of the next function.
	glGenBuffers(1, &VBO);

	// OpenGL has a rather unique way of using handles. In many APIs the handle is simply passed to any relevant function 
	// and the action is taken on that handle. In OpenGL we bind the handle to a target name and then execute commands on that target. 
	// These commmands affect the bounded handle until another one is bound in its stead or the call above takes zero as the handle. 
	// The target GL_ARRAY_BUFFER means that the buffer will contain an array of vertices. 
	// Another useful target is GL_ELEMENT_ARRAY_BUFFER which means that the buffer contains the indices of the vertices in another buffer.
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// After binding our object we fill it with data. The call above takes the target name (same as what we used for binding), 
	// the size of the data in bytes, address of the array of vertices and a flag that indicates the usage pattern for this data. 
	// Since we are not going to change the buffer contents we specify GL_STATIC_DRAW. The opposite will be GL_DYNAMIC_DRAW. 
	// While this is only a hint to OpenGL it is a good thing to give some thought as to the proper flag to use. 
	// The driver can rely on it for optimization heuristics (such as what is the best place in memory to store the buffer).
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

	// In the shaders tutorial you will see that vertex attributes used in the shader (position, normal, etc) 
	// have an index mapped to them that enable you to create the binding between the data in the C/C++ program and 
	// the attribute name inside the shader. In addition you must also enable each vertex attribute index. 
	// In this tutorial we are not yet using any shader but the vertex position we have loaded into the buffer is treated as 
	// vertex attribute index 0 in the fixed function pipeline (which becomes active when there is no shader bound). 
	// You must enable each vertex attribute or else the data will not be accessible by the pipeline.
	glEnableVertexAttribArray(0);

	// Here we bind our buffer again as we prepare for making the draw call. 
	// In this small program we only have one vertex buffer so making this call every frame is redundent but 
	// in more complex programs there are multiple buffers to store your various models and you must update the pipeline 
	// state with the buffer you intend to use.
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	/* This call tells the pipeline how to interpret the data inside the buffer. 
	The first parameter specifies the index of the attribute. In our case we know that it is zero by default but when we start using shaders 
	we will either need to explicitly set the index in the shader or query it. The second parameter is the number of components 
	in the attribute (3 for X, Y and Z). The third parameter is the data type of each component. 
	The next parameter indicates whether we want our attribute to be normalized before it is used in the pipeline. 
	It our case we want the data to pass un-changed. The fifth parameter (called the 'stride') is the number of bytes between 
	two instances of that attribute in the buffer. When there is only one attribute (e.g. the buffer contains only vertex positions) 
	and the data is tightly packed we pass the value zero. If we have an array of structures that contain a position and normal 
	(each one is a vector of 3 floats) we will pass the size of the structure in bytes (6 * 4 = 24). 
	The last parameter is useful in the case of the previous example. We need to specify the offset inside the structure where 
	the pipeline will find our attribute. In the case of the structure with the position and normal the offset of the position is 
	zero while the offset of the normal is 12.
	*/
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// Finally, we make the call to draw the geometry. All the commands that we've seen so far are important but they only 
	// set the stage for the draw command. This is where the GPU really starts to work. 
	// It will now combine the parameters of the draw call with the state that was built up to this point and render the results to the screen.
	glDrawArrays(GL_POINTS, 0, 1);

	glDisableVertexAttribArray(0);

	return 0;
}
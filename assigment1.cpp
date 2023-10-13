
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include <iostream>

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);


// settings
const unsigned int SCR_WIDTH = 500;
const unsigned int SCR_HEIGHT = 600;
float rotateAngle = 0.0;
float translate_X = 0.0;
float translate_Y = 0.0;
float scale_X = 0.0;
float scale_Y = 0.0;


const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
"}\n\0";

const char* fragmentShaderSource1 = "#version 330 core\n"
"out vec4 FragColor1;\n"
"void main()\n"
"{\n"
"   FragColor1 = vec4(0.5f, 0.196f, 0.003f, 0.0f);\n"
"}\n\0";

const char* fragmentShaderSource2 = "#version 330 core\n"
"out vec4 FragColor2;\n"
"void main()\n"
"{\n"
"   FragColor2 = vec4(0.992f, 0.502f, 0.168f, 0.0f);\n"
"}\n\0";
const char* fragmentShaderSource3 = "#version 330 core\n"
"out vec4 FragColor3;\n"
"void main()\n"
"{\n"
"   FragColor3 = vec4(0.3137f, 0.294f, 0.2078f,0.0f);\n"
"}\n\0";
const char* fragmentShaderSource4 = "#version 330 core\n"
"out vec4 FragColor4;\n"
"void main()\n"
"{\n"
"   FragColor4 = vec4(0.996f, 0.851f, 0.745f,0.0f);\n"
"}\n\0";

const char* fragmentShaderSource5 = "#version 330 core\n"
"out vec4 FragColor5;\n"
"void main()\n"
"{\n"
"   FragColor5 = vec4(0.145f, 0.1137f, 0.1068f, 0.0f);\n"
"}\n\0";
const char* fragmentShaderSource6 = "#version 330 core\n"
"out vec4 FragColor6;\n"
"void main()\n"
"{\n"
"   FragColor6 = vec4(0.5f, 0.196f, 0.003f, 0.0f);\n"
"}\n\0";
const char* fragmentShaderSource7 = "#version 330 core\n"
"out vec4 FragColor7;\n"
"void main()\n"
"{\n"
"   FragColor7 = vec4(1.0f, 0.839f, 0.1804f,0.0f);\n"
"}\n\0";
const char* fragmentShaderSource8 = "#version 330 core\n"
"out vec4 FragColor8;\n"
"void main()\n"
"{\n"
"   FragColor8 = vec4(0.0f, 0.0f, 0.0f,0.0f);\n"
"}\n\0";


int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    // build and compile our shader program
    // ------------------------------------
    // vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }


    // fragment shader1
    unsigned int fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER); //creates fragment shader object
    glShaderSource(fragmentShader1, 1, &fragmentShaderSource1, NULL);     //linkup the source code and object
    glCompileShader(fragmentShader1);    //compiles the code
    // check for shader compile errors
    glGetShaderiv(fragmentShader1, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader1, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders           // to access the vertex and compile shader, the unsigned int vertexshader and fragmentshader are used. // now we need to link the vertex shader and fragment shader, otherwise we won't know which fragment shader maps to which vertex
    unsigned int shaderProgram1 = glCreateProgram();  //this create program does the link up between vertex and fragment
    glAttachShader(shaderProgram1, vertexShader); //attaches vertex
    glAttachShader(shaderProgram1, fragmentShader1); //attaches fragment
    glLinkProgram(shaderProgram1); //links all the attached shaders
    // check for linking errors
    glGetProgramiv(shaderProgram1, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram1, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    // fragment shader2
    unsigned int fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER); //creates fragment shader object
    glShaderSource(fragmentShader2, 1, &fragmentShaderSource2, NULL);     //linkup the source code and object
    glCompileShader(fragmentShader2);    //compiles the code
    // check for shader compile errors
    glGetShaderiv(fragmentShader2, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader2, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders           // to access the vertex and compile shader, the unsigned int vertexshader and fragmentshader are used. // now we need to link the vertex shader and fragment shader, otherwise we won't know which fragment shader maps to which vertex
    unsigned int shaderProgram2 = glCreateProgram();  //this create program does the link up between vertex and fragment
    glAttachShader(shaderProgram2, vertexShader); //attaches vertex
    glAttachShader(shaderProgram2, fragmentShader2); //attaches fragment
    glLinkProgram(shaderProgram2); //links all the attached shaders
    // check for linking errors
    glGetProgramiv(shaderProgram2, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram2, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    // fragment shader3
    unsigned int fragmentShader3 = glCreateShader(GL_FRAGMENT_SHADER); //creates fragment shader object
    glShaderSource(fragmentShader3, 1, &fragmentShaderSource3, NULL);     //linkup the source code and object
    glCompileShader(fragmentShader3);    //compiles the code
    // check for shader compile errors
    glGetShaderiv(fragmentShader3, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader3, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders           // to access the vertex and compile shader, the unsigned int vertexshader and fragmentshader are used. // now we need to link the vertex shader and fragment shader, otherwise we won't know which fragment shader maps to which vertex
    unsigned int shaderProgram3 = glCreateProgram();  //this create program does the link up between vertex and fragment
    glAttachShader(shaderProgram3, vertexShader); //attaches vertex
    glAttachShader(shaderProgram3, fragmentShader3); //attaches fragment
    glLinkProgram(shaderProgram3); //links all the attached shaders
    // check for linking errors
    glGetProgramiv(shaderProgram3, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram3, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    //fragment shader4
    unsigned int fragmentShader4 = glCreateShader(GL_FRAGMENT_SHADER); //creates fragment shader object
    glShaderSource(fragmentShader4, 1, &fragmentShaderSource4, NULL);     //linkup the source code and object
    glCompileShader(fragmentShader4);    //compiles the code
    // check for shader compile errors
    glGetShaderiv(fragmentShader4, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader4, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders           // to access the vertex and compile shader, the unsigned int vertexshader and fragmentshader are used. // now we need to link the vertex shader and fragment shader, otherwise we won't know which fragment shader maps to which vertex
    unsigned int shaderProgram4 = glCreateProgram();  //this create program does the link up between vertex and fragment
    glAttachShader(shaderProgram4, vertexShader); //attaches vertex
    glAttachShader(shaderProgram4, fragmentShader4); //attaches fragment
    glLinkProgram(shaderProgram4); //links all the attached shaders
    // check for linking errors
    glGetProgramiv(shaderProgram4, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram4, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    // fragment shader5
    unsigned int fragmentShader5 = glCreateShader(GL_FRAGMENT_SHADER); //creates fragment shader object
    glShaderSource(fragmentShader5, 1, &fragmentShaderSource5, NULL);     //linkup the source code and object
    glCompileShader(fragmentShader5);    //compiles the code
    // check for shader compile errors
    glGetShaderiv(fragmentShader5, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader5, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders           // to access the vertex and compile shader, the unsigned int vertexshader and fragmentshader are used. // now we need to link the vertex shader and fragment shader, otherwise we won't know which fragment shader maps to which vertex
    unsigned int shaderProgram5 = glCreateProgram();  //this create program does the link up between vertex and fragment
    glAttachShader(shaderProgram5, vertexShader); //attaches vertex
    glAttachShader(shaderProgram5, fragmentShader5); //attaches fragment
    glLinkProgram(shaderProgram5); //links all the attached shaders
    // check for linking errors
    glGetProgramiv(shaderProgram5, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram5, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    // fragment shader6
    unsigned int fragmentShader6 = glCreateShader(GL_FRAGMENT_SHADER); //creates fragment shader object
    glShaderSource(fragmentShader6, 1, &fragmentShaderSource6, NULL);     //linkup the source code and object
    glCompileShader(fragmentShader6);    //compiles the code
    // check for shader compile errors
    glGetShaderiv(fragmentShader6, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader6, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders           // to access the vertex and compile shader, the unsigned int vertexshader and fragmentshader are used. // now we need to link the vertex shader and fragment shader, otherwise we won't know which fragment shader maps to which vertex
    unsigned int shaderProgram6 = glCreateProgram();  //this create program does the link up between vertex and fragment
    glAttachShader(shaderProgram6, vertexShader); //attaches vertex
    glAttachShader(shaderProgram6, fragmentShader6); //attaches fragment
    glLinkProgram(shaderProgram6); //links all the attached shaders
    // check for linking errors
    glGetProgramiv(shaderProgram6, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram6, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    // fragment shader7
    unsigned int fragmentShader7 = glCreateShader(GL_FRAGMENT_SHADER); //creates fragment shader object
    glShaderSource(fragmentShader7, 1, &fragmentShaderSource7, NULL);     //linkup the source code and object
    glCompileShader(fragmentShader7);    //compiles the code
    // check for shader compile errors
    glGetShaderiv(fragmentShader7, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader7, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders           // to access the vertex and compile shader, the unsigned int vertexshader and fragmentshader are used. // now we need to link the vertex shader and fragment shader, otherwise we won't know which fragment shader maps to which vertex
    unsigned int shaderProgram7 = glCreateProgram();  //this create program does the link up between vertex and fragment
    glAttachShader(shaderProgram7, vertexShader); //attaches vertex
    glAttachShader(shaderProgram7, fragmentShader7); //attaches fragment
    glLinkProgram(shaderProgram7); //links all the attached shaders
    // check for linking errors
    glGetProgramiv(shaderProgram7, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram7, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader8
    unsigned int fragmentShader8 = glCreateShader(GL_FRAGMENT_SHADER); //creates fragment shader object
    glShaderSource(fragmentShader8, 1, &fragmentShaderSource8, NULL);     //linkup the source code and object
    glCompileShader(fragmentShader8);    //compiles the code
    // check for shader compile errors
    glGetShaderiv(fragmentShader8, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader8, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders           // to access the vertex and compile shader, the unsigned int vertexshader and fragmentshader are used. // now we need to link the vertex shader and fragment shader, otherwise we won't know which fragment shader maps to which vertex
    unsigned int shaderProgram8 = glCreateProgram();  //this create program does the link up between vertex and fragment
    glAttachShader(shaderProgram8, vertexShader); //attaches vertex
    glAttachShader(shaderProgram8, fragmentShader8); //attaches fragment
    glLinkProgram(shaderProgram8); //links all the attached shaders
    // check for linking errors
    glGetProgramiv(shaderProgram8, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram8, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteShader(fragmentShader1);
    glDeleteShader(fragmentShader2);
    glDeleteShader(fragmentShader3);
    glDeleteShader(fragmentShader4);
    glDeleteShader(fragmentShader5);
    glDeleteShader(fragmentShader6);
    glDeleteShader(fragmentShader7);
    glDeleteShader(fragmentShader8);

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------

    float vertices[] = {
        //uporer tomb 
        // 39ta point=(266-228)+1
        //index=0-4
        0.0048714933646900604, 0.8489837056946077, 0.0f,//center point
        -0.335629094574164, 0.6545019317990928, 0.0f,//start point
        0.008399126490844733, 0.9896270787838064, 0.0f,
        0.35763480598017816, 0.6633210146144801, 0.0f,
        -0.335629094574164, 0.6545019317990928, 0.0f,//start point

        //tomb er nicher ta straight boro orange color body ta 
        // 6ta data=(274-269)+1
        //index=5-10
        0.016630270451872597, 0.23446161599193682, 0.0f,//center point
        -0.327565933142953, 0.6545439274315471, 0.0f,//starting point
        - 0.31295145304888283, -0.04850495548462974, 0.0f,
        0.38081639509490994, -0.05530824794221423, 0.0f,
        0.35780278850999503, 0.6581135561901561, 0.0f,
        -0.327565933142953, 0.6545439274315471, 0.0f,//starting point


        //tomb er nicher chikon yellow line ta 6ta data
        //index=46-51
        

        //majher shada boro part ta pura
        //27ta point=318-292+1
        //index=11-17
        0.002183772887619284, -0.06769695951621024, 0.0f,//center point
        -0.0010078951789016521, 0.5312447505459431, 0.0f,//staring point
        0.2405509826977994, 0.29291953636821766, 0.0f,
        0.27498740131026356, -0.5246094406181756, 0.0f,
        - 0.20880228456240557, -0.5271291785654291, 0.0f,
        - 0.23500755921384187, 0.2852343356290944, 0.0f,
        - 0.0010078951789016521, 0.5312447505459431, 0.0f,//staring point

        //majher white tay 3ta j choto glass ase, tar shb cheye left er ta
        //6ta point
        //index=79-84

        //majher white tay 3ta j choto glass ase, tar shb cheye right er ta
        //6ta point
        //index=85-90


        //majher white tay 3ta j choto glass ase, tar shb cheye boro ta
        //20ta point=363-344
        //index=91-110

        //majher white tay jei chikon line gula ase tar first ta mane ekdom uporer ta
        //6ta point
        //index=111-116

        //majher white tay jei chikon line gula ase tar second ta mane ekdom nicher ta
            //6ta point
            //index=117-122

        //majher white tay  niche jei yellow part ta ase rectangular
            //6ta point
            //index=18-23
0.018814043339492326, -0.5832353435242732, 0.0f,//center point
        -0.20880228456240557, -0.5271291785654291, 0.0f,//starting point
- 0.20561061649588463, -0.6260708886275825, 0.0f,
0.2701159079455735, -0.6235931463127833, 0.0f,
0.26692423987905256, -0.5246514362506298, 0.0f,
- 0.20880228456240557, -0.5271291785654291, 0.0f,//starting point


        //majher white tay  niche jei yellow part ta ase rectangular er nicher bam pasher choto rectangle ta
            //6ta point
            //index=24-29
-0.08432722996808373, -0.6358558709894171, 0.0f,//center point
            -0.14110532504619533, -0.6257349235679488, 0.0f,//starting point
- 0.140265412397111, -0.6517722156895682, 0.0f,
- 0.019317990928943818, -0.651142281202755, 0.0f,
- 0.020157903578028158, -0.6251049890811355, 0.0f,
            - 0.14110532504619533, -0.6257349235679488, 0.0f,//starting point


            //majher white tay  niche jei yellow part ta ase rectangular er nicher dan pasher choto rectangle ta
            //6ta point
            //index=30-35
0.15756761296825106, -0.6345960020157904, 0.0f,//center point
            0.10078951789013946, -0.6244750545943221, 0.0f,//starting point
0.1016294305392238, -0.6505123467159415, 0.0f,
0.22257685200739097, -0.6505123467159415, 0.0f,
0.22173693935830663, -0.6238451201075088, 0.0f,
            0.10078951789013946, -0.6244750545943221, 0.0f,//starting point

            //majher white tay  niche jei yellow part ta ase rectangular er nicher bam pasher choto rectangle tar nicher part
            //6ta point
            //index=36-41
-0.0749202082983369, -0.6774735427515537, 0.0f,//center point
            -0.13976146480766038, -0.6673945909625398, 0.0f,//starting point
- 0.16311103645220904, -0.6922980010078952, 0.0f,
0.006215353603225449, -0.6922980010078952, 0.0f,
- 0.018814043339493214, -0.6667646564757266, 0.0f,
            - 0.13976146480766038, -0.6673945909625398, 0.0f,//starting point

            //majher white tay  niche jei yellow part ta ase rectangular er nicher dan pasher choto rectangle tar nicher part
            //6ta point
            //index=42-47
            0.1669746346379979, -0.676213673777927, 0.0f,//center point
            0.10196539559885753, -0.6667646564757266, 0.0f,//starting point
            0.07878380648412531, -0.6922980010078952, 0.0f,
            0.2481101965395598, -0.6922980010078952, 0.0f,
            0.2229128170670247, -0.6667646564757266, 0.0f,
            0.10196539559885753, -0.6667646564757266, 0.0f,//starting point


            //left side er brown color wing ta
            //33ta point
            //index=48-52
            -0.3206786494204601, -0.30896186796573155, 0.0f,//center point
            -0.2286242230808, 0.08735091550478757, 0.0f,//starting point
            - 0.717453384847976, -0.50894506971275, 0.0f,
            - 0.20964219721149036, -0.5010918864438099, 0.0f,
            -0.2286242230808, 0.08735091550478757, 0.0f,//starting point

            //right side er brown wing ta
            //34ta point
            //index=53-57
            0.3717453384847973, -0.274105493028725, 0.0f,//center point
            0.25516546279186914, 0.08987065345204104, 0.0f,//starting point
            0.2741474886611788, -0.4985721484965564, 0.0f,
            0.8145472870821431, -0.5009658995464472, 0.0f,
            0.25516546279186914, 0.08987065345204104, 0.0f,//starting point

            //left side shada capsule er moto part ta
                //40ta point
            //index=59-65
            -0.4528809003863601, 0.039307911977154664, 0.0f,//center point
            -0.46780196539559924, 0.41416092726356457, 0.0f,//start point
            - 0.6121283386527803, 0.21547959012262718, 0.0f,
            - 0.6121283386527803, -0.37402150176381657, 0.0f,
            - 0.32151856206954443, -0.29735091550478757, 0.0f,
            - 0.32151856206954443, 0.21707542415588765, 0.0f,
            - 0.46780196539559924, 0.41416092726356457, 0.0f,//start point

                //right side shada capsule er moto part ta
                //39ta point
            //index=66-72
    0.5403997984209643, -0.0023937510498908132, 0.0f,//center point
    0.5266252309759785, 0.4246178397446666, 0.0f,//start point
    0.3719133210146146, 0.22068704854695098, 0.0f,
    0.3719133210146146, -0.3103897194691754, 0.0f,
    0.7026709222240881, -0.38279858894674925, 0.0f,
    0.7026709222240881, 0.2119099613640183, 0.0f,
    0.5266252309759785, 0.4246178397446666, 0.0f,//start point
    
              //left side shada capsule er moto part tar paaaa kalo part
              //6ta point
      //index=73-78
    -0.4426339660675289, -0.5283470519066016, 0.0f,//center point
    -0.5965059633798089, -0.5083151352259365, 0.0f,//starting point
    - 0.5949941206114566, -0.5551822610448514, 0.0f,
    - 0.2966571476566435, -0.5536284226440451, 0.0f,
    - 0.2981689904249958, -0.5067612968251303, 0.0f,
    -0.5965059633798089, -0.5083151352259365, 0.0f,//starting point

    //left side shada capsule er moto part tar paaaa orange part
              //6ta point
      //index=79-84
    - 0.4488493196707548, -0.5856710902066182, 0.0f,//center point
    -0.5627414748866122, -0.5539223920712, 0.0f,//start point
    - 0.6012094742146816, -0.6125062993448682, 0.0f,
    - 0.31093566269108, -0.6109944565765162, 0.0f,
    - 0.35309927767512184, -0.5539223920712, 0.0f,
    -0.5627414748866122, -0.5550142785150345, 0.0f,//start point

    //left side shada capsule er moto part tar paaaa yellow part
              //6ta point
      //index=85-90
    -0.4387703678817405, -0.6481185956660505, 0.0f,//center point
    -0.6253989585083155, -0.6126322862422309, 0.0f,//start point
    - 0.6793213505795399, -0.6910381320342682, 0.0f,
    - 0.21972114900050377, -0.6916443809843774, 0.0f,
    - 0.27868301696623554, -0.6126322862422309, 0.0f,
    -0.6253989585083155, -0.6126322862422309, 0.0f,//start point
    

              //right side shada capsule er moto part tar paaaa kalo part
              //6ta point
      //index=91-95
                0.5491348899714428, -0.523181589114732, 0.0f,//center point
                0.39526289265916326, -0.5031496724340669, 0.0f,//start point
                0.3967747354275155, -0.5484209642197211, 0.0f,
                0.7031748698135396, -0.5484209642197211, 0.0f,
                0.7018310095750042, -0.5031496724340669, 0.0f,
                0.39526289265916326, -0.5031496724340669, 0.0f,//start point

                //right side shada capsule er moto part tar paaaa orange part
                //6ta point
        //index=96-101
                .5590458592306398, -0.5804216361498402, 0.0f,//center point
                0.43709054258357094, -0.5498068200907107, 0.0f,//start point
                0.3986225432555015, -0.6072988409205444, 0.0f,
                0.6969595162103142, -0.605745002519738, 0.0f,
                0.6547959012262723, -0.5498068200907107, 0.0f,
                0.43709054258357094, -0.5498068200907107, 0.0f,//start point

                //right side shada capsule er moto part tar paaaa yellow part
              //6ta point
      //index=102-107
                0.5449353267260202, -0.6429951285066351, 0.0f,//center point
                0.38249622039307907, -0.6073828321854529, 0.0f,//start point
                0.7211490005039476, -0.6056190156223753, 0.0f,
                0.7881740299008899, -0.6833949269275994, 0.0f,
                0.3124475054594318, -0.6833949269275994, 0.0f,
                0.38249622039307907, -0.6073828321854529, 0.0f,//start point


              //nicher dhuaa lfet part
              //22ta point
      //index=108-129
               -0.4449857214849655, -0.9554426339660671, 0.0f,//center point
               // -0.41760456912481114, -1.0542583571308584, 0.0f,//center point
                -0.5583739291113727, -0.690408197547455, 0.0f,//start point
                - 0.6018814043339495, -0.8416764656475728, 0.0f,
                - 0.6739459096253992, -0.8576768016126326, 0.0f,
                - 0.7295481269947928, -0.8840080631614311, 0.0f,
                - 0.7685200739123133, -0.925877708718293, 0.0f,
                - 0.767008231143961, -0.9727448345372081, 0.0f,
                - 0.7419788342012428, -0.9986561397614648, 0.0f,
                - 0.7821266588274822, -1.0040735763480597, 0.0f,
                - 0.8135393919032423, -1.030278850999496, 0.0f,
                0.040651772215689164, -1.0102049386863767, 0.0f,
                0.023517554174365962, -0.9790441794053419, 0.0f,
                - 0.009407021669746829, -0.9583823282378632, 0.0f,
                - 0.042163614984041864, -0.9429279354947082, 0.0f,
                - 0.09071056610112604, -0.9379724508651097, 0.0f,
                - 0.12296321182597048, -0.938140433394927, 0.0f,
                - 0.11573996304384337, -0.9120611456408534, 0.0f,
                - 0.1409373425163789, -0.8809423819922728, 0.0f,
                - 0.16579875692927937, -0.8602385351923403, 0.0f,
                - 0.21451369057617997, -0.850075592138418, 0.0f,
                - 0.27918696455568615, -0.8452040987737275, 0.0f,
                - 0.34066857046867094, -0.6892743154711909, 0.0f,
                -0.5583739291113727, -0.690408197547455, 0.0f,//start point

        //left side shada capsule er moto part tar uporer kalo part ta
          //6ta point
      //index=130-135
      - 0.4644716949437262, 0.1486225432555015, 0.0f,//center point
        -0.6121283386527803, 0.17020829833697304, 0.0f,//start point
        - 0.3200067193011926, 0.17020829833697304, 0.0f,
        - 0.31849487653284037, 0.12334117251805798, 0.0f,
        - 0.6121283386527803, 0.12334117251805798, 0.0f,
        - 0.6121283386527803, 0.16861246430371257, 0.0f,//start point

        //left side shada capsule er moto part tar majher kalo part ta
              //14ta point
      //index=136-141
        -0.4589282714597682, -0.02322358474718622, 0.0f,//center point
        -0.6121283386527803, 0.001973794725348643, 0.0f,//start point
        - 0.3064001343860241, 0.001973794725348643, 0.0f,
        - 0.2969931127162777, -0.05010078951789021, 0.0f,
        - 0.6121283386527803, -0.05010078951789021, 0.0f,
        - 0.6121283386527803, 0.001973794725348643, 0.0f,//start point


        //left side shada capsule er moto part tar nicher kalo part ta lowest
              //6ta point
      //index=142-147
        -0.45590458592306415, -0.11695783638501589, 0.0f,//center point
        -0.6121283386527803, -0.09696791533680482, 0.0f,//start point
        -0.27112380312447515, -0.09696791533680482, 0.0f,
        - 0.26961196035612334, -0.14202922896018833, 0.0f,
        - 0.6121283386527803, -0.14202922896018833, 0.0f,
        - 0.6121283386527803, -0.09696791533680482, 0.0f,//start point

          //right side shada capsule er moto part tar uporer kalo part ta
              //6ta point
      //index=148-153
        0.5355283050562738, 0.1486225432555015, 0.0f,//center point
        0.3734251637829664, 0.17020829833697304, 0.0f,//start point
        0.7026709222240881, 0.17020829833697304, 0.0f,
        0.7026709222240881, 0.12334117251805798, 0.0f,
        0.3734251637829664, 0.12334117251805798, 0.0f,
        0.3734251637829664, 0.16861246430371257, 0.0f,//start point

                    //right side shada capsule er moto part tar majher kalo part ta
              //6ta point
      //index=154-159
                    0.5355283050562738, -0.02322358474718622, 0.0f,//center point
                    0.3734251637829664, 0.001973794725348643, 0.0f,//start point
                    0.7026709222240881, 0.001973794725348643, 0.0f,
                    0.7026709222240881, -0.05010078951789021, 0.0f,
                    0.3734251637829664, -0.05010078951789021, 0.0f,
                    0.3734251637829664, 0.001973794725348643, 0.0f,//start point

              //right side shada capsule er moto part tar nicher kalo part ta
              //6ta point
      //index=160-165
                    0.5355283050562738, -0.11695783638501589, 0.0f,//center point
                    0.3734251637829664, -0.09696791533680482, 0.0f,//start point
                    0.7026709222240881, -0.09696791533680482, 0.0f,
                    0.7026709222240881, -0.14202922896018833, 0.0f,
                    0.3734251637829664, -0.14202922896018833, 0.0f,
                    0.3734251637829664, -0.09696791533680482, 0.0f,//start point


                    //majher  shada capsule er moto part tar uporer kalo part ta
                          //6ta point
                  //index=166-171
                    0.011926759616999849, 0.13027045187300534, 0.0f,//center point
                    -0.23500755921384187, 0.1342180413237024, 0.0f,//start point
                    0.25405509826977994, 0.1342180413237024, 0.0f,
                    0.25498740131026356, 0.12111540399798426, 0.0f,
                    -0.23880228456240557, 0.12111540399798426, 0.0f,
                   -0.23500755921384187, 0.1342180413237024, 0.0f,//start point
                   /*
                   0.011926759616999849, 0.13027045187300534
                   - 0.2301360658491518, 0.1342180413237024
                   0.2536536200235173, 0.13673777927095587
                   0.2541575676129679, 0.12111540399798426
                   - 0.2296321182597012, 0.1185956660507308
                   */
                   //majher  shada capsule er moto part tar nicher kalo part ta
                         //6ta point
                 //index=172-177
                    0.011926759616999849, -0.43027045187300534, 0.0f,//center point
                    -0.23500755921384187, -0.4342180413237024, 0.0f,//start point
                    0.26505509826977994, -0.4342180413237024, 0.0f,
                    0.26598740131026356, -0.42111540399798426, 0.0f,
                    -0.23880228456240557, -0.42111540399798426, 0.0f,
                    -0.23500755921384187, -0.4342180413237024, 0.0f,//start point

            //tomb er nicher ta straight boro orange color body tar majhe ekta chikon line
        // 6ta data
        //index=178-183
                    -0.010414916848648037, 0.5728624223080798, 0.0f,//center point
                    -0.327565933142953, 0.5638469679153367, 0.0f,//starting point
                    -0.327565933142953, 0.5639643877036788, 0.0f,
                    0.35780278850999503, 0.5638469679153367, 0.0f,
                    0.35780278850999503, 0.5639643877036788, 0.0f,
                    -0.327565933142953, 0.5638469679153367, 0.0f,//starting point
                    /*
                    -0.3253821602553333, 0.5868469679153367
                    0.3601545439274316, 0.5852091382496221
                    0.36116243910633283, 0.5539643877036788
                    - 0.3243742650764321, 0.5556022173693935
                    - 0.010414916848648037, 0.5728624223080798
                    */

    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);


    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
 // ------
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // create transformations
        glm::mat4 translationMatrix;
        glm::mat4 rotationMatrix;
        glm::mat4 scaleMatrix;
        glm::mat4 modelMatrix;
        glm::mat4 identityMatrix = glm::mat4(1.0f);
        translationMatrix = glm::translate(identityMatrix, glm::vec3(.2f, .7f, 0.0f));  //generates translation matrix
        rotationMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f)); //rotation matrix   // rotating wrt z axis
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(scale_X, scale_Y, 1.0f)); //scaling matrix
        modelMatrix = translationMatrix * rotationMatrix * scaleMatrix; //composite matrix, right to left
        //modelMatrix = rotationMatrix * translationMatrix;
        //modelMatrix = translationMatrix * rotationMatrix;

        //black color
        //white dhua
        glUseProgram(shaderProgram8); //activates the shaderProgram 
        unsigned int transformLoc8 = glGetUniformLocation(shaderProgram8, "transform"); //location of uniform variable is needed, so we can transfer the data of modelMatrix into it
        glUniformMatrix4fv(transformLoc8, 1, GL_TRUE, glm::value_ptr(modelMatrix)); // here sends the ModelMatrix data to transformLoc
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        //left dhua
        //glDrawArrays(GL_TRIANGLE_FAN, 91, 22);
        //glDrawArrays(GL_LINE_LOOP, 108, 22);
        glDrawArrays(GL_TRIANGLE_FAN, 91, 6);//right dhuar upor kalo part ta
        glDrawArrays(GL_LINE_LOOP, 91, 6);
        glDrawArrays(GL_TRIANGLE_FAN, 73, 6);//left dhua upor kalo part ta
        glDrawArrays(GL_LINE_LOOP, 73, 6);
        //uporer tomb er border
        glDrawArrays(GL_LINE_LOOP, 1, 3);//tomb borcder
        glDrawArrays(GL_LINE_LOOP, 6, 4);//tomb er nicher body border
        //dhua er uporer orange part
        glDrawArrays(GL_LINE_LOOP, 79, 6);//left
        glDrawArrays(GL_LINE_LOOP, 96, 6);//right
        //dhua uporer part
        glDrawArrays(GL_LINE_LOOP, 103, 5);//yellow part er border
        glDrawArrays(GL_LINE_LOOP, 85, 5);//yellow part er border
        
        glDrawArrays(GL_TRIANGLE_FAN, 18, 6);//
        glDrawArrays(GL_LINE_LOOP, 18, 6);
        glDrawArrays(GL_TRIANGLE_FAN, 24, 6);
        glDrawArrays(GL_LINE_LOOP, 24, 6);
        glDrawArrays(GL_TRIANGLE_FAN, 30, 6);
        glDrawArrays(GL_LINE_LOOP, 30, 6);
        glDrawArrays(GL_TRIANGLE_FAN, 36, 6);
        glDrawArrays(GL_LINE_LOOP, 36, 6);
        glDrawArrays(GL_TRIANGLE_FAN, 42, 6);
        glDrawArrays(GL_LINE_LOOP, 42, 6);


        //brown color
        glUseProgram(shaderProgram1); //activates the shaderProgram 
        unsigned int transformLoc1 = glGetUniformLocation(shaderProgram1, "transform"); //location of uniform variable is needed, so we can transfer the data of modelMatrix into it
        glUniformMatrix4fv(transformLoc1, 1, GL_TRUE, glm::value_ptr(modelMatrix)); // here sends the ModelMatrix data to transformLoc
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        

        //orange color
        glUseProgram(shaderProgram2); //activates the shaderProgram 
        unsigned int transformLoc2 = glGetUniformLocation(shaderProgram2, "transform"); //location of uniform variable is needed, so we can transfer the data of modelMatrix into it
        glUniformMatrix4fv(transformLoc2, 1, GL_TRUE, glm::value_ptr(modelMatrix)); // here sends the ModelMatrix data to transformLoc
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        //uporer tomb brown color
        glDrawArrays(GL_TRIANGLE_FAN, 0, 10);
        //tomb er nicher body
        glDrawArrays(GL_TRIANGLE_FAN, 5, 6);
        
        //dhua er uporer orange part
        glDrawArrays(GL_TRIANGLE_FAN, 79, 6);//left
        glDrawArrays(GL_TRIANGLE_FAN, 96, 6);//right
        
        //white (not pure) cream color
        glUseProgram(shaderProgram4); //activates the shaderProgram 
        unsigned int transformLoc4 = glGetUniformLocation(shaderProgram4, "transform"); //location of uniform variable is needed, so we can transfer the data of modelMatrix into it
        glUniformMatrix4fv(transformLoc4, 1, GL_TRUE, glm::value_ptr(modelMatrix)); // here sends the ModelMatrix data to transformLoc
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        //tomb er nicher body majher white body ta 
        glDrawArrays(GL_TRIANGLE_FAN, 11, 7);
        glDrawArrays(GL_LINE_LOOP, 11, 7);

        //magenda
        glUseProgram(shaderProgram7); //activates the shaderProgram 
        unsigned int transformLoc7 = glGetUniformLocation(shaderProgram7, "transform"); //location of uniform variable is needed, so we can transfer the data of modelMatrix into it
        glUniformMatrix4fv(transformLoc7, 1, GL_TRUE, glm::value_ptr(modelMatrix)); // here sends the ModelMatrix data to transformLoc
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        //tomb er nicher white body tar niche jei yellow part ta ase oi ta
        //glDrawArrays(GL_TRIANGLE_FAN, 123, 4);
        //glDrawArrays(GL_TRIANGLE_FAN, 129, 4);
        //left side capsule
        glDrawArrays(GL_TRIANGLE_FAN, 59, 5);
        //glDrawArrays(GL_LINE_LOOP, 59, 7);
        //right side capsule
        glDrawArrays(GL_TRIANGLE_FAN, 66, 5);
        //glDrawArrays(GL_LINE_LOOP, 66, 7);

        
        //light ash color
        glUseProgram(shaderProgram3); //activates the shaderProgram 
        unsigned int transformLoc3 = glGetUniformLocation(shaderProgram3, "transform"); //location of uniform variable is needed, so we can transfer the data of modelMatrix into it
        glUniformMatrix4fv(transformLoc3, 1, GL_TRUE, glm::value_ptr(modelMatrix)); // here sends the ModelMatrix data to transformLoc
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        //tomb er nicher white body er nicher jei light ash part gula ase
        //dhua uporer part
        glDrawArrays(GL_TRIANGLE_FAN, 102, 6);
        glDrawArrays(GL_TRIANGLE_FAN, 85, 6);
        

        //glass color
        glUseProgram(shaderProgram5); //activates the shaderProgram 
        unsigned int transformLoc5 = glGetUniformLocation(shaderProgram5, "transform"); //location of uniform variable is needed, so we can transfer the data of modelMatrix into it
        glUniformMatrix4fv(transformLoc4, 1, GL_TRUE, glm::value_ptr(modelMatrix)); // here sends the ModelMatrix data to transformLoc
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        //tomb er nicher body majher white body ta glass gula 3ta glass
        //glDrawArrays(GL_TRIANGLE_FAN, 79, 4);
        //glDrawArrays(GL_LINE_LOOP, 79, 6);
        //glDrawArrays(GL_TRIANGLE_FAN, 85, 4);
        //glDrawArrays(GL_LINE_LOOP, 85, 6);
        //glDrawArrays(GL_TRIANGLE_FAN, 91, 118);
        //glDrawArrays(GL_LINE_LOOP, 91, 120);
        //left side er white capsule tay jei black part gula ase
        glDrawArrays(GL_TRIANGLE_FAN, 131, 6);//uporer ta
        glDrawArrays(GL_LINE_LOOP, 131, 5);
        glDrawArrays(GL_TRIANGLE_FAN, 137, 6);//majher ta
        glDrawArrays(GL_LINE_LOOP, 137, 5);
        glDrawArrays(GL_TRIANGLE_FAN, 143, 6);//nicher ta
        glDrawArrays(GL_LINE_LOOP, 143, 5);
        //right side er white capsule tay jei black part gula ase
        glDrawArrays(GL_TRIANGLE_FAN, 149, 6);//uporer ta
        glDrawArrays(GL_LINE_LOOP, 149, 5);
        glDrawArrays(GL_TRIANGLE_FAN, 155, 6);//majher ta
        glDrawArrays(GL_LINE_LOOP, 155, 5);
        glDrawArrays(GL_TRIANGLE_FAN, 161, 6);//nicher ta
        glDrawArrays(GL_LINE_LOOP, 161, 5);
        //majher white capsule tay jei black part gula ase
        glDrawArrays(GL_TRIANGLE_FAN, 167, 6);//uporer ta
        glDrawArrays(GL_LINE_LOOP, 167, 5);
        glDrawArrays(GL_TRIANGLE_FAN, 173, 6);//nicher ta
        glDrawArrays(GL_LINE_LOOP, 173, 5);
        //orange body te chikon ekta straight line
       // glDrawArrays(GL_TRIANGLE_FAN, 179, 6);
        //glDrawArrays(GL_LINE_LOOP, 179, 6);

        glDrawArrays(GL_LINE_LOOP, 48, 5);//left wing
        glDrawArrays(GL_LINE_LOOP, 53, 5);//right wing




        //wing color
        glUseProgram(shaderProgram6); //activates the shaderProgram 
        unsigned int transformLoc6 = glGetUniformLocation(shaderProgram6, "transform"); //location of uniform variable is needed, so we can transfer the data of modelMatrix into it
        glUniformMatrix4fv(transformLoc6, 1, GL_TRUE, glm::value_ptr(modelMatrix)); // here sends the ModelMatrix data to transformLoc
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        //tomb er nicher body majher white body tar moddher chikon line gula
        //glDrawArrays(GL_TRIANGLE_FAN, 111, 4);
        //glDrawArrays(GL_TRIANGLE_FAN, 117, 4);
        //glDrawArrays(GL_LINE_LOOP, 111, 6);
        //glDrawArrays(GL_LINE_LOOP, 117, 6);
        //whtie color body r pasher 2pasher 2 wings
        glDrawArrays(GL_TRIANGLE_FAN, 48, 5);//left wing
        glDrawArrays(GL_TRIANGLE_FAN, 53, 5);//right wing
        

        
        

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

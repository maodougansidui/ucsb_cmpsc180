#include "Triangle.hpp"
#include "rasterizer.hpp"
#include <eigen3/Eigen/Eigen>
#include <iostream>
#include <opencv2/opencv.hpp>

constexpr double MY_PI = 3.1415926;

Eigen::Matrix4f get_view_matrix(Eigen::Vector3f eye_pos)
{
    Eigen::Matrix4f view = Eigen::Matrix4f::Identity();

    Eigen::Matrix4f translate;
    translate << 1, 0, 0, -eye_pos[0], 0, 1, 0, -eye_pos[1], 0, 0, 1,
        -eye_pos[2], 0, 0, 0, 1;

    view = translate * view;

    return view;
}
Eigen::Matrix4f get_rotation(Eigen::Vector3f axis, float angle){
    const float PI=3.14159265;
    float cosT=cos(angle*PI/180.0);
    float sinT= sin(angle*PI/180.0);
    Eigen::Matrix3f iden= Eigen::Matrix3f::Identity();
    Eigen::Matrix3f N;
    N << 0,-axis(2),axis(1),axis(2),0,-axis(0),-axis(1),
        axis(0),0;
    Eigen::Matrix3f cur;
    cur=cosT*iden+(1-cosT)*axis*axis.transpose()+sinT*N;
    Eigen::Matrix4f res;
    res(0,0)=cur(0,0);res(0,1)=cur(0,1);res(0,2)=cur(0,2);res(0,3)=0;
    res(1,0)=cur(1,0);res(1,1)=cur(1,1);res(1,2)=cur(1,2);res(1,3)=0;
    res(2,0)=cur(2,0);res(2,1)=cur(2,1);res(2,2)=cur(2,2);res(2,3)=0;
    res(3,0)=0;res(3,1)=0;res(3,2)=0;res(3,3)=1;
    return res;

}
Eigen::Matrix4f get_model_matrix(float rotation_angle)
{
    Eigen::Matrix4f model = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    const float PI=3.14159265;
    float cosT=cos(rotation_angle*PI/180.0);
    float sinT= sin(rotation_angle*PI/180.0);
    Eigen::Matrix4f rotation;
    rotation << cosT, -sinT, 0, 0, sinT, cosT, 0, 0, 0,0,1,0,
        0,0,0,1;

    model=rotation*model;
    return model;
}

Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio,
                                      float zNear, float zFar)
{
    Eigen::Matrix4f projection = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    zNear=-zNear; zFar=-zFar;
    Eigen::Matrix4f m_per_ortho;
    Eigen::Matrix4f m_ortho_tran;
    Eigen::Matrix4f m_ortho_scale;
    const float PI=3.14159265;
    float tanT=tan(eye_fov/2*PI/180.0);
    float top=abs(zNear)*tanT;
    float right=top*aspect_ratio;
    m_ortho_tran << 1,0,0,0,0,1,0,0,0,0,1,-(zNear+zFar)/2,
        0,0,0,1;
    
    m_ortho_scale << 1/right , 0,0,0,0,1/top,0,0,
        0,0,2/(zNear-zFar),0,0,0,0,1;

    m_per_ortho << zNear,0,0,0,0,zNear,0,0,0,0,zNear+zFar,
        -zNear*zFar,0,0,1,0;

    projection=m_ortho_scale*m_ortho_tran*m_per_ortho*projection;

    return projection;
}

int main(int argc, const char** argv)
{
    float angle = 0;
    bool command_line = false;
    std::string filename = "output.png";

    if (argc >= 3) {
        command_line = true;
        angle = std::stof(argv[2]); // -r by default
        if (argc == 4) {
            filename = std::string(argv[3]);
        }
        else
            return 0;
    }

    rst::rasterizer r(700, 700);

    Eigen::Vector3f eye_pos = {0, 0, 5};
    Eigen::Vector3f axis={1,1,0};
    // axis=axis/sqrt(2);

    std::vector<Eigen::Vector3f> pos{{2, 0, -2}, {0, 2, -2}, {-2, 0, -2}};

    std::vector<Eigen::Vector3i> ind{{0, 1, 2}};

    auto pos_id = r.load_positions(pos);
    auto ind_id = r.load_indices(ind);

    int key = 0;
    int frame_count = 0;

    if (command_line) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_rotation(axis,angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);
        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);

        cv::imwrite(filename, image);

        return 0;
    }

    while (key != 27) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_rotation(axis,angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);

        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);
        cv::imshow("image", image);
        key = cv::waitKey(10);

        std::cout << "frame count: " << frame_count++ << '\n';

        if (key == 'a') {
            angle += 10;
        }
        else if (key == 'd') {
            angle -= 10;
        }
    }

    return 0;
}

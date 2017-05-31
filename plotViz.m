% visualization script
% pointsFileName = './Input/001_boxPoints.txt';
% pointsFileName = './Input/002_boxPermute.txt';
% pointsFileName = './Input/003_ellipse.txt';
% pointsFileName = './Input/004_ellipseHD.txt';
pointsFileName = './Input/005_ellipseHDRotated.txt';
% pointsFileName = './Input/006_ellipseUneven.txt';
% pointsFileName = './Input/007_ellipseUneven.txt';
% pointsFileName = './Input/008_ellipseUnevenHD.txt';
% pointsFileName = './Input/009_ellipseUnevenHD.txt';
triangleFileName = './triangle.txt';

% Read points
Data = dlmread(pointsFileName);
X = Data(2:end,1);
Y = Data(2:end,2);
Z = Data(2:end,3);

% Read Triangles
Triangles = dlmread(triangleFileName);

trimesh(Triangles, X, Y, Z);
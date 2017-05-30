% visualization script
pointsFileName = './Input/004_ellipseHD.txt';
triangleFileName = './triangle.txt';

% Read points
Data = dlmread(pointsFileName);
X = Data(2:end,1);
Y = Data(2:end,2);
Z = Data(2:end,3);

% Read Triangles
Triangles = dlmread(triangleFileName);

trimesh(Triangles, X, Y, Z);
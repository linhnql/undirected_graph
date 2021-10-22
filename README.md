# qLinhGraph
Project I - Undirected Graph in C

- Sử dụng ngôn ngữ C để cài đặt cấu trúc dữ liệu đơn đồ thị vô hướng G = (V, E)
- Tệp tin văn bản đầu vào được lấy từ thư viện đồ thị SNAP 
- Thực hiện các thao tác cơ bản: Duyệt đồ thị theo chiều rộng (BFS), chiều sâu (DFS) và kiểm tra tập đỉnh bao phủ (Vertex Cover) (https://en.wikipedia.org/wiki/Vertex_cover)

KIỂM TRA TẬP ĐỈNH PHỦ:

Đọc lần lượt phần tử trong file input. Với mỗi đỉnh, thực hiện xoá các cạnh liên quan đến đỉnh đó. Ví dụ với đỉnh A, phải xoá đỉnh A nếu A có trong danh sách kề của các đỉnh còn lại và xóa luôn danh sách kề của A:
- Duyệt danh sách kề đỉnh A.
- Với mỗi phân tử trong A, ví dụ a, thực hiện duyệt đỉnh kề của a để tìm phần tử A và xoá nếu có. Nếu đã tìm được và xoá, nhảy đến đỉnh b kế tiếp trong danh sách kề của A.
- Thực hiện công việc trên cho đến khi A rỗng.
- Cuối cùng, gán danh sách kề của A bằng rỗng.

# qLinhGraph
Project I - Undirected Graph in C

- Sử dụng ngôn ngữ C để cài đặt cấu trúc dữ liệu đơn đồ thị vô hướng G = (V, E)
- Tệp tin văn bản đầu vào được lấy từ thư viện đồ thị SNAP (roadNet-CA, roadNet-PA, roadNet-TX)
- Thực hiện các thao tác cơ bản: 
      + Duyệt đồ thị theo chiều rộng (BFS) 
      + Duyệt đồ thị theo chiều sâu (DFS) 
      + Kiểm tra tập đỉnh bao phủ (Vertex Cover) (https://en.wikipedia.org/wiki/Vertex_cover)

Kiểm tra tập phủ:
- Đọc lần lượt phần tử trong file input. Với mỗi đỉnh, thực hiện xoá các cạnh liên quan đến đỉnh đó. Ví dụ với đỉnh A:
- Duyệt danh sách kề đỉnh A:
- Với mỗi phân tử trong A, ví dụ a, thực hiện duyệt đỉnh kề của a, nếu đến đỉnh A(đỉnh cần xoá) thì thực hiện xoá đỉnh này trong danh sách kề của a.
- Thực hiện công việc trên cho đến khi A rỗng.
- Cuối cùng, gán danh sách kề của A bằng rỗng.

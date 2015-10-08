GDB là một phần mềm gỡ rối (debug) không thể thiếu trong lập trình Linux.

Nó có thể giúp cho lập trình viên biết được:
   + đoạn mã gây ra coredump (khi chương trình bị hỏng và coredump của chương trình được tạo ra)

   + bằng break point, ta biết chương trình có chạy qua đoạn code đó hay ko, và trạng thái của các biến global/biến local khi đó như thế nào.

   + bằng watchpoint, ta cũng có thể biết được đoạn code nào gây ra sự thay đổi cho một biến global nào đó.

   + bằng tracepoint, ta có thể lưu lại sự giá trị của một số biến khi chương trình chạy qua một đoạn code nào đó.

   + bằng gdbserver, ta có thể debug một chương trình từ một máy khác, không nhất thiết là phải ở chính nơi chương trình đang chạy (điều này rất có ý nghĩa đối với các hệ thống nhúng)

   + đối với những chương trình nhiều threads, gdb giúp ta biết được có bao nhiêu đang chạy, trạng thái của các threadsđó.

   + trong những trường hợp mà chương trình đã được tối ưu hóa khi biên dịch các biến ta thấy ở mã nguồn có thể bị "optimize out" thì khả năng debug tới cấp assembly sẽ gíup cho lập trình viên biết được trạng thanh ghi thật sự của CPU.

   + Ngoài ra gdb cũng có khả năng script hóa, giúp cho ta không phải thực hiện những công việc lặp đi lặp lại.

Tuy nhiên gdb cũng có một số hạn chế:
   + Không thể biết những lỗi liên quan tới race condition.
   + Chương trình chạy trong môi trường gdb thì châm hơn so với bình thường -> gây ra những vấn đề liên quan đến thời gian.
   + Khi attach vào một chương trình đang chạy để gỡ rối thì gdb sẽ làm cho chương trỉnh tạm dừng một thời gian ngắn, nếu timer watch dog của chương trình nhỏ hơn thời gian này thì chương trình sẽ bị hỏng trước khi gdb có thể làm cho chương trình tiếp tục chạy.

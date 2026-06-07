type MinStack struct {
    stack []int
    minval int
}

func Constructor() MinStack {
    return MinStack{stack:  make([]int, 0, 1), minval: 0}
}

func (this *MinStack) Push(val int) {
    if len(this.stack) == 0 {
        this.stack = append(this.stack, 0)
        this.minval = val
        fmt.Println("Push: empty stack: %v", val)
        return
    }
    if this.minval > val {
        this.stack = append(this.stack, val-this.minval)
        this.minval = val
        fmt.Println("Push: new min: %v", val)
        return
    }
    this.stack = append(this.stack, val-this.minval)
    fmt.Println("Push: not new min: %v", val)
}

func (this *MinStack) Pop() {
    if len(this.stack) == 0 {
        return
    }
    stackTop := this.top()
    if stackTop < 0 {
        this.minval = this.minval - stackTop
    }
    this.stack = this.stack[0:len(this.stack)-1]
}

func (this *MinStack) top() int {
    if len(this.stack) == 0 {
        return 0
    }
    return this.stack[len(this.stack)-1]
}

func (this *MinStack) Top() int {
    stackTop := this.top()
    if stackTop > 0 {
        return stackTop + this.minval
    }
    return this.minval
}

func (this *MinStack) GetMin() int {
    return this.minval
}

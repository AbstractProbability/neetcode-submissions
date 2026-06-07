// import "strconv"
type Stack []int

func isOp(val string) bool {
    if val == "+" || val == "-" || val == "*" || val == "/" {
        return true
    }
    return false
}

func (stack *Stack) top() int {
    return (*stack)[len(*stack)-1]
}

func (stack *Stack) pop() {
    (*stack)[len(*stack)-1] = 0
    (*stack) = (*stack)[:len(*stack)-1]
}

func (stack *Stack) push(val int) {
    *stack = append(*stack, val)
}

func handleOp(op1 int, op2 int, opString string) int {
    switch opString {
    case "+" :
        return op1+op2
    case "-":
        return op1-op2
    case "*":
        return op1*op2
    case "/":
        return op1/op2
    default:
        return op1
    }
}

func evalRPN(tokens []string) int {
    var stack Stack = make([]int, 0, 1)
    for _, token := range tokens {
        if isOp(token) {
            op2 := stack.top()
            stack.pop()
            op1 := stack.top()
            stack.pop()
            stack.push(handleOp(op1, op2, token))
        } else {
            val, _ := strconv.Atoi(token)
            stack.push(val)
        }
    }
    return stack.top()
}

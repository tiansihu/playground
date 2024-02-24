import random

from enum import Enum

class OpType(Enum):
    ADD = 0
    SUB = 1

def has_carry(lhs: int, rhs: int) -> bool:
    while lhs != 0 and rhs != 0:
        a = lhs % 10
        b = rhs % 10

        if a + b > 9:
            return True
        
        a //= 10
        b //= 10

    return True

def make_add_sub(maximum: int, can_carry: bool) -> tuple[int, int, OpType]:
    lhs = random.randrange(0, maximum)
    rhs = random.randrange(0, maximum - lhs)

    if not can_carry:
        while has_carry(lhs, rhs):
            lhs = random.randrange(0, maximum)
            rhs = random.randrange(0, maximum)

    optype = OpType(random.randrange(2))

    if optype == OpType.SUB:
        lhs = lhs + rhs
    
    return (lhs, rhs, optype)

def print_prob(prob: tuple[int, int, OpType]) -> None:
    print(f"{prob[0]} {'+' if prob[2] == OpType.ADD else '-'} {prob[1]} = ")

def pro_maker() -> None:
    for i in range(20):
        prob = make_add_sub(100, True)
        print_prob(prob)

if __name__ == "__main__":
    random.seed()
    pro_maker()
import os

def parse_string(input_string):
    # "$" 이후의 문자열을 찾는다.
    if '$' in input_string:
        parts = input_string.split('$', 1)
        variable_part = parts[1]
        
        # " 이후의 문자열을 찾는다.
        if '"' in variable_part:
            variable_part = variable_part.split('"', 1)[1]
        
        # 환경변수 값을 찾는다.
        variable_value = os.getenv(variable_part)
        
        # 만약 환경변수가 존재하면, 값을 문자열에 대체한다.
        if variable_value:
            return parts[0] + variable_value

    # 환경변수가 아닌 경우, 입력된 문자열을 반환한다.
    return input_string


print(parse_string("$\"HOME\""))
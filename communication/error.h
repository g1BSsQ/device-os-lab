#ifndef COMM_ERROR_H
#define COMM_ERROR_H

#define COMM_OK 0
#define COMM_ERR_OVERFLOW -1
#define COMM_ERR_CRC -2
#define COMM_ERR_TIMEOUT -3

const char* comm_error_str(int code);
void comm_report_error(int code);

#endif // COMM_ERROR_H

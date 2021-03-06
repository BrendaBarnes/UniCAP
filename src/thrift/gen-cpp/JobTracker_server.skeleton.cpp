// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "JobTracker.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::ntu::cap;

class JobTrackerHandler : virtual public JobTrackerIf {
public:
    JobTrackerHandler() {
        // Your initialization goes here
    }

    int64_t register_task_tracker(const int64_t node_id, const std::string& node_name, const int64_t storage_weight) {
        // Your implementation goes here
        printf("register_task_tracker\n");
    }

    void get_all_task_tracker_info(std::map<int64_t, TaskTrackerInfo> & _return) {
        // Your implementation goes here
        printf("get_all_task_tracker_info\n");
    }

    void fetch_cpu_task(TaskNode& _return, const int64_t task_tracker_id) {
        // Your implementation goes here
        printf("fetch_cpu_task\n");
    }

    void fetch_gpu_task(TaskNode& _return, const int64_t task_tracker_id) {
        // Your implementation goes here
        printf("fetch_gpu_task\n");
    }

    int64_t complete_cpu_task(const int64_t stage_id, const int64_t task_id) {
        // Your implementation goes here
        printf("complete_cpu_task\n");
    }

    int64_t complete_gpu_task(const int64_t stage_id, const int64_t task_id) {
        // Your implementation goes here
        printf("complete_gpu_task\n");
    }

};

int main(int argc, char **argv) {
    int port = 9090;
    shared_ptr<JobTrackerHandler> handler(new JobTrackerHandler());
    shared_ptr<TProcessor> processor(new JobTrackerProcessor(handler));
    shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
    server.serve();
    return 0;
}


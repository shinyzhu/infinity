//
// Created by JinHai on 2022/7/26.
//

#include "physical_operator.h"
#include "scheduler/operator_pipeline.h"

namespace infinity {

PhysicalOperator::~PhysicalOperator() = default;

std::shared_ptr<OperatorPipeline>
PhysicalOperator::GenerateOperatorPipeline() {
    if(operator_pipeline_.expired()) {
        std::shared_ptr<OperatorPipeline> shared_operator_pipeline = std::make_shared<OperatorPipeline>(shared_from_this());
        operator_pipeline_ = std::weak_ptr<OperatorPipeline>(shared_operator_pipeline);

        // TODO: If the operator is executed, the task state need to be changed to DONE.
        return shared_operator_pipeline;
    } else {
        return operator_pipeline_.lock();
    }
}

}



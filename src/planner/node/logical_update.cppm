//
// Created by JinHai on 2022/7/23.
//

module;

import stl;
import parser;
import logical_node;
import logical_node_type;
import column_binding;
import table_collection_entry;
import base_expression;
export module logical_update;

namespace infinity {

export class LogicalUpdate final : public LogicalNode {

public:
    LogicalUpdate(u64 node_id, TableCollectionEntry *table_entry_ptr, const Vector<Pair<SizeT, SharedPtr<BaseExpression>>> &update_columns)
        : LogicalNode(node_id, LogicalNodeType::kUpdate), table_entry_ptr_(table_entry_ptr), update_columns_(update_columns) {}

    [[nodiscard]] Vector<ColumnBinding> GetColumnBindings() const final;

    [[nodiscard]] SharedPtr<Vector<String>> GetOutputNames() const final;

    [[nodiscard]] SharedPtr<Vector<SharedPtr<DataType>>> GetOutputTypes() const final;

    String ToString(i64 &space) const final;

    inline String name() final { return "LogicalUpdate"; }

    TableCollectionEntry *table_entry_ptr_{};
    const Vector<Pair<SizeT, SharedPtr<BaseExpression>>> update_columns_;
};

} // namespace infinity
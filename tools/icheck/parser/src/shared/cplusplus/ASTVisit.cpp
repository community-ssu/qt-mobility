/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt Mobility Components.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Solutions Commercial License Agreement provided
** with the Software or, alternatively, in accordance with the terms
** contained in a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** Please note Third Party Software included with Qt Solutions may impose
** additional restrictions and it is the user's responsibility to ensure
** that they have met the licensing requirements of the GPL, LGPL, or Qt
** Solutions Commercial license and the relevant license of the Third
** Party Software they are using.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#include "AST.h"
#include "ASTVisitor.h"

using namespace CPlusPlus;

void SimpleSpecifierAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void AttributeSpecifierAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(attribute_list, visitor);
    }
    visitor->endVisit(this);
}

void AttributeAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(expression_list, visitor);
    }
    visitor->endVisit(this);
}

void TypeofSpecifierAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void DeclaratorAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(attribute_list, visitor);
        accept(ptr_operator_list, visitor);
        accept(core_declarator, visitor);
        accept(postfix_declarator_list, visitor);
        accept(post_attribute_list, visitor);
        accept(initializer, visitor);
    }
    visitor->endVisit(this);
}

void SimpleDeclarationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(decl_specifier_list, visitor);
        accept(declarator_list, visitor);
    }
    visitor->endVisit(this);
}

void EmptyDeclarationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void AccessDeclarationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

#ifdef ICHECK_BUILD
void QPropertyDeclarationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void QEnumDeclarationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void QFlagsDeclarationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void QDeclareFlagsDeclarationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}
#endif

void AsmDefinitionAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void BaseSpecifierAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
    }
    visitor->endVisit(this);
}

void CompoundLiteralAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(type_id, visitor);
        accept(initializer, visitor);
    }
    visitor->endVisit(this);
}

void QtMethodAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(declarator, visitor);
    }
    visitor->endVisit(this);
}

void QtMemberDeclarationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(type_id, visitor);
    }
    visitor->endVisit(this);
}

void BinaryExpressionAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(left_expression, visitor);
        accept(right_expression, visitor);
    }
    visitor->endVisit(this);
}

void CastExpressionAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(type_id, visitor);
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void ClassSpecifierAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(attribute_list, visitor);
        accept(name, visitor);
        accept(base_clause_list, visitor);
        accept(member_specifier_list, visitor);
    }
    visitor->endVisit(this);
}

void CaseStatementAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
        accept(statement, visitor);
    }
    visitor->endVisit(this);
}

void CompoundStatementAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(statement_list, visitor);
    }
    visitor->endVisit(this);
}

void ConditionAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(type_specifier_list, visitor);
        accept(declarator, visitor);
    }
    visitor->endVisit(this);
}

void ConditionalExpressionAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(condition, visitor);
        accept(left_expression, visitor);
        accept(right_expression, visitor);
    }
    visitor->endVisit(this);
}

void CppCastExpressionAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(type_id, visitor);
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void CtorInitializerAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(member_initializer_list, visitor);
    }
    visitor->endVisit(this);
}

void DeclarationStatementAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(declaration, visitor);
    }
    visitor->endVisit(this);
}

void DeclaratorIdAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
    }
    visitor->endVisit(this);
}

void NestedDeclaratorAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(declarator, visitor);
    }
    visitor->endVisit(this);
}

void FunctionDeclaratorAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(parameters, visitor);
        accept(cv_qualifier_list, visitor);
        accept(exception_specification, visitor);
        accept(as_cpp_initializer, visitor);
    }
    visitor->endVisit(this);
}

void ArrayDeclaratorAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void DeleteExpressionAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void DoStatementAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(statement, visitor);
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void NamedTypeSpecifierAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
    }
    visitor->endVisit(this);
}

void ElaboratedTypeSpecifierAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
    }
    visitor->endVisit(this);
}

void EnumSpecifierAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
        accept(enumerator_list, visitor);
    }
    visitor->endVisit(this);
}

void EnumeratorAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void ExceptionDeclarationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(type_specifier_list, visitor);
        accept(declarator, visitor);
    }
    visitor->endVisit(this);
}

void ExceptionSpecificationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(type_id_list, visitor);
    }
    visitor->endVisit(this);
}

void ExpressionOrDeclarationStatementAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
        accept(declaration, visitor);
    }
    visitor->endVisit(this);
}

void ExpressionStatementAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void FunctionDefinitionAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(decl_specifier_list, visitor);
        accept(declarator, visitor);
        accept(ctor_initializer, visitor);
        accept(function_body, visitor);
    }
    visitor->endVisit(this);
}

void ForeachStatementAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(type_specifier_list, visitor);
        accept(declarator, visitor);
        accept(initializer, visitor);
        accept(expression, visitor);
        accept(statement, visitor);
    }
    visitor->endVisit(this);
}

void ForStatementAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(initializer, visitor);
        accept(condition, visitor);
        accept(expression, visitor);
        accept(statement, visitor);
    }
    visitor->endVisit(this);
}

void IfStatementAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(condition, visitor);
        accept(statement, visitor);
        accept(else_statement, visitor);
    }
    visitor->endVisit(this);
}

void ArrayInitializerAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(expression_list, visitor);
    }
    visitor->endVisit(this);
}

void LabeledStatementAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(statement, visitor);
    }
    visitor->endVisit(this);
}

void LinkageBodyAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(declaration_list, visitor);
    }
    visitor->endVisit(this);
}

void LinkageSpecificationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(declaration, visitor);
    }
    visitor->endVisit(this);
}

void MemInitializerAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
        accept(expression_list, visitor);
    }
    visitor->endVisit(this);
}

void NestedNameSpecifierAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(class_or_namespace_name, visitor);
    }
    visitor->endVisit(this);
}

void QualifiedNameAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(nested_name_specifier_list, visitor);
        accept(unqualified_name, visitor);
    }
    visitor->endVisit(this);
}

void OperatorFunctionIdAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(op, visitor);
    }
    visitor->endVisit(this);
}

void ConversionFunctionIdAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(type_specifier_list, visitor);
        accept(ptr_operator_list, visitor);
    }
    visitor->endVisit(this);
}

void SimpleNameAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void DestructorNameAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void TemplateIdAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(template_argument_list, visitor);
    }
    visitor->endVisit(this);
}

void NamespaceAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(attribute_list, visitor);
        accept(linkage_body, visitor);
    }
    visitor->endVisit(this);
}

void NamespaceAliasDefinitionAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
    }
    visitor->endVisit(this);
}

void NewPlacementAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(expression_list, visitor);
    }
    visitor->endVisit(this);
}

void NewArrayDeclaratorAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void NewExpressionAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(new_placement, visitor);
        accept(type_id, visitor);
        accept(new_type_id, visitor);
        accept(new_initializer, visitor);
    }
    visitor->endVisit(this);
}

void NewInitializerAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void NewTypeIdAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(type_specifier_list, visitor);
        accept(ptr_operator_list, visitor);
        accept(new_array_declarator_list, visitor);
    }
    visitor->endVisit(this);
}

void OperatorAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void ParameterDeclarationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(type_specifier_list, visitor);
        accept(declarator, visitor);
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void ParameterDeclarationClauseAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(parameter_declaration_list, visitor);
    }
    visitor->endVisit(this);
}

void CallAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(expression_list, visitor);
    }
    visitor->endVisit(this);
}

void ArrayAccessAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void PostIncrDecrAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void MemberAccessAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(member_name, visitor);
    }
    visitor->endVisit(this);
}

void TypeidExpressionAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void TypenameCallExpressionAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
        accept(expression_list, visitor);
    }
    visitor->endVisit(this);
}

void TypeConstructorCallAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(type_specifier_list, visitor);
        accept(expression_list, visitor);
    }
    visitor->endVisit(this);
}

void PostfixExpressionAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(base_expression, visitor);
        accept(postfix_expression_list, visitor);
    }
    visitor->endVisit(this);
}

void PointerToMemberAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(nested_name_specifier_list, visitor);
        accept(cv_qualifier_list, visitor);
    }
    visitor->endVisit(this);
}

void PointerAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(cv_qualifier_list, visitor);
    }
    visitor->endVisit(this);
}

void ReferenceAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void BreakStatementAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void ContinueStatementAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void GotoStatementAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void ReturnStatementAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void SizeofExpressionAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void NumericLiteralAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void BoolLiteralAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void ThisExpressionAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void NestedExpressionAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void StringLiteralAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void SwitchStatementAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(condition, visitor);
        accept(statement, visitor);
    }
    visitor->endVisit(this);
}

void TemplateDeclarationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(template_parameter_list, visitor);
        accept(declaration, visitor);
    }
    visitor->endVisit(this);
}

void ThrowExpressionAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void TranslationUnitAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(declaration_list, visitor);
    }
    visitor->endVisit(this);
}

void TryBlockStatementAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(statement, visitor);
        accept(catch_clause_list, visitor);
    }
    visitor->endVisit(this);
}

void CatchClauseAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(exception_declaration, visitor);
        accept(statement, visitor);
    }
    visitor->endVisit(this);
}

void TypeIdAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(type_specifier_list, visitor);
        accept(declarator, visitor);
    }
    visitor->endVisit(this);
}

void TypenameTypeParameterAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
        accept(type_id, visitor);
    }
    visitor->endVisit(this);
}

void TemplateTypeParameterAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(template_parameter_list, visitor);
        accept(name, visitor);
        accept(type_id, visitor);
    }
    visitor->endVisit(this);
}

void UnaryExpressionAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(expression, visitor);
    }
    visitor->endVisit(this);
}

void UsingAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
    }
    visitor->endVisit(this);
}

void UsingDirectiveAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(name, visitor);
    }
    visitor->endVisit(this);
}

void WhileStatementAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(condition, visitor);
        accept(statement, visitor);
    }
    visitor->endVisit(this);
}

void ObjCClassForwardDeclarationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(attribute_list, visitor);
        accept(identifier_list, visitor);
    }
    visitor->endVisit(this);
}

void ObjCClassDeclarationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(attribute_list, visitor);
        accept(class_name, visitor);
        accept(category_name, visitor);
        accept(superclass, visitor);
        accept(protocol_refs, visitor);
        accept(inst_vars_decl, visitor);
        accept(member_declaration_list, visitor);
    }
    visitor->endVisit(this);
}

void ObjCProtocolForwardDeclarationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(attribute_list, visitor);
        accept(identifier_list, visitor);
    }
    visitor->endVisit(this);
}

void ObjCProtocolDeclarationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(attribute_list, visitor);
        accept(name, visitor);
        accept(protocol_refs, visitor);
        accept(member_declaration_list, visitor);
    }
    visitor->endVisit(this);
}

void ObjCProtocolRefsAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(identifier_list, visitor);
    }
    visitor->endVisit(this);
}

void ObjCMessageArgumentAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(parameter_value_expression, visitor);
    }
    visitor->endVisit(this);
}

void ObjCMessageExpressionAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(receiver_expression, visitor);
        accept(selector, visitor);
        accept(argument_list, visitor);
    }
    visitor->endVisit(this);
}

void ObjCProtocolExpressionAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void ObjCTypeNameAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(type_id, visitor);
    }
    visitor->endVisit(this);
}

void ObjCEncodeExpressionAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(type_name, visitor);
    }
    visitor->endVisit(this);
}

void ObjCSelectorWithoutArgumentsAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void ObjCSelectorArgumentAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void ObjCSelectorWithArgumentsAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(selector_argument_list, visitor);
    }
    visitor->endVisit(this);
}

void ObjCSelectorExpressionAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(selector, visitor);
    }
    visitor->endVisit(this);
}

void ObjCInstanceVariablesDeclarationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(instance_variable_list, visitor);
    }
    visitor->endVisit(this);
}

void ObjCVisibilityDeclarationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void ObjCPropertyAttributeAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(method_selector, visitor);
    }
    visitor->endVisit(this);
}

void ObjCPropertyDeclarationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(attribute_list, visitor);
        accept(property_attribute_list, visitor);
        accept(simple_declaration, visitor);
    }
    visitor->endVisit(this);
}

void ObjCMessageArgumentDeclarationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(type_name, visitor);
        accept(attribute_list, visitor);
    }
    visitor->endVisit(this);
}

void ObjCMethodPrototypeAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(type_name, visitor);
        accept(selector, visitor);
        accept(argument_list, visitor);
        accept(attribute_list, visitor);
    }
    visitor->endVisit(this);
}

void ObjCMethodDeclarationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(method_prototype, visitor);
        accept(function_body, visitor);
    }
    visitor->endVisit(this);
}

void ObjCSynthesizedPropertyAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
    }
    visitor->endVisit(this);
}

void ObjCSynthesizedPropertiesDeclarationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(property_identifier_list, visitor);
    }
    visitor->endVisit(this);
}

void ObjCDynamicPropertiesDeclarationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(property_identifier_list, visitor);
    }
    visitor->endVisit(this);
}

void ObjCFastEnumerationAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(type_specifier_list, visitor);
        accept(declarator, visitor);
        accept(initializer, visitor);
        accept(fast_enumeratable_expression, visitor);
        accept(statement, visitor);
    }
    visitor->endVisit(this);
}

void ObjCSynchronizedStatementAST::accept0(ASTVisitor *visitor)
{
    if (visitor->visit(this)) {
        accept(synchronized_object, visitor);
        accept(statement, visitor);
    }
    visitor->endVisit(this);
}


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
#include "ASTMatcher.h"

using namespace CPlusPlus;

bool SimpleSpecifierAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (SimpleSpecifierAST *_other = pattern->asSimpleSpecifier())
        return matcher->match(this, _other);

    return false;
}

bool AttributeSpecifierAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (AttributeSpecifierAST *_other = pattern->asAttributeSpecifier())
        return matcher->match(this, _other);

    return false;
}

bool AttributeAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (AttributeAST *_other = pattern->asAttribute())
        return matcher->match(this, _other);

    return false;
}

bool TypeofSpecifierAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (TypeofSpecifierAST *_other = pattern->asTypeofSpecifier())
        return matcher->match(this, _other);

    return false;
}

bool DeclaratorAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (DeclaratorAST *_other = pattern->asDeclarator())
        return matcher->match(this, _other);

    return false;
}

bool SimpleDeclarationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (SimpleDeclarationAST *_other = pattern->asSimpleDeclaration())
        return matcher->match(this, _other);

    return false;
}

bool EmptyDeclarationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (EmptyDeclarationAST *_other = pattern->asEmptyDeclaration())
        return matcher->match(this, _other);

    return false;
}

bool AccessDeclarationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (AccessDeclarationAST *_other = pattern->asAccessDeclaration())
        return matcher->match(this, _other);

    return false;
}

#ifdef ICHECK_BUILD
bool QPropertyDeclarationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (QPropertyDeclarationAST *_other = pattern->asQPropertyDeclarationAST())
        return matcher->match(this, _other);

    return false;
}

bool QEnumDeclarationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (QEnumDeclarationAST *_other = pattern->asQEnumDeclarationAST())
        return matcher->match(this, _other);

    return false;
}

bool QFlagsDeclarationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (QFlagsDeclarationAST *_other = pattern->asQFlagsDeclarationAST())
        return matcher->match(this, _other);

    return false;
}

bool QDeclareFlagsDeclarationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (QDeclareFlagsDeclarationAST *_other = pattern->asQDeclareFlagsDeclarationAST())
        return matcher->match(this, _other);

    return false;
}
#endif

bool AsmDefinitionAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (AsmDefinitionAST *_other = pattern->asAsmDefinition())
        return matcher->match(this, _other);

    return false;
}

bool BaseSpecifierAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (BaseSpecifierAST *_other = pattern->asBaseSpecifier())
        return matcher->match(this, _other);

    return false;
}

bool CompoundLiteralAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (CompoundLiteralAST *_other = pattern->asCompoundLiteral())
        return matcher->match(this, _other);

    return false;
}

bool QtMethodAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (QtMethodAST *_other = pattern->asQtMethod())
        return matcher->match(this, _other);

    return false;
}

bool QtMemberDeclarationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (QtMemberDeclarationAST *_other = pattern->asQtMemberDeclaration())
        return matcher->match(this, _other);

    return false;
}

bool BinaryExpressionAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (BinaryExpressionAST *_other = pattern->asBinaryExpression())
        return matcher->match(this, _other);

    return false;
}

bool CastExpressionAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (CastExpressionAST *_other = pattern->asCastExpression())
        return matcher->match(this, _other);

    return false;
}

bool ClassSpecifierAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ClassSpecifierAST *_other = pattern->asClassSpecifier())
        return matcher->match(this, _other);

    return false;
}

bool CaseStatementAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (CaseStatementAST *_other = pattern->asCaseStatement())
        return matcher->match(this, _other);

    return false;
}

bool CompoundStatementAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (CompoundStatementAST *_other = pattern->asCompoundStatement())
        return matcher->match(this, _other);

    return false;
}

bool ConditionAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ConditionAST *_other = pattern->asCondition())
        return matcher->match(this, _other);

    return false;
}

bool ConditionalExpressionAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ConditionalExpressionAST *_other = pattern->asConditionalExpression())
        return matcher->match(this, _other);

    return false;
}

bool CppCastExpressionAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (CppCastExpressionAST *_other = pattern->asCppCastExpression())
        return matcher->match(this, _other);

    return false;
}

bool CtorInitializerAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (CtorInitializerAST *_other = pattern->asCtorInitializer())
        return matcher->match(this, _other);

    return false;
}

bool DeclarationStatementAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (DeclarationStatementAST *_other = pattern->asDeclarationStatement())
        return matcher->match(this, _other);

    return false;
}

bool DeclaratorIdAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (DeclaratorIdAST *_other = pattern->asDeclaratorId())
        return matcher->match(this, _other);

    return false;
}

bool NestedDeclaratorAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (NestedDeclaratorAST *_other = pattern->asNestedDeclarator())
        return matcher->match(this, _other);

    return false;
}

bool FunctionDeclaratorAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (FunctionDeclaratorAST *_other = pattern->asFunctionDeclarator())
        return matcher->match(this, _other);

    return false;
}

bool ArrayDeclaratorAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ArrayDeclaratorAST *_other = pattern->asArrayDeclarator())
        return matcher->match(this, _other);

    return false;
}

bool DeleteExpressionAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (DeleteExpressionAST *_other = pattern->asDeleteExpression())
        return matcher->match(this, _other);

    return false;
}

bool DoStatementAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (DoStatementAST *_other = pattern->asDoStatement())
        return matcher->match(this, _other);

    return false;
}

bool NamedTypeSpecifierAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (NamedTypeSpecifierAST *_other = pattern->asNamedTypeSpecifier())
        return matcher->match(this, _other);

    return false;
}

bool ElaboratedTypeSpecifierAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ElaboratedTypeSpecifierAST *_other = pattern->asElaboratedTypeSpecifier())
        return matcher->match(this, _other);

    return false;
}

bool EnumSpecifierAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (EnumSpecifierAST *_other = pattern->asEnumSpecifier())
        return matcher->match(this, _other);

    return false;
}

bool EnumeratorAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (EnumeratorAST *_other = pattern->asEnumerator())
        return matcher->match(this, _other);

    return false;
}

bool ExceptionDeclarationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ExceptionDeclarationAST *_other = pattern->asExceptionDeclaration())
        return matcher->match(this, _other);

    return false;
}

bool ExceptionSpecificationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ExceptionSpecificationAST *_other = pattern->asExceptionSpecification())
        return matcher->match(this, _other);

    return false;
}

bool ExpressionOrDeclarationStatementAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ExpressionOrDeclarationStatementAST *_other = pattern->asExpressionOrDeclarationStatement())
        return matcher->match(this, _other);

    return false;
}

bool ExpressionStatementAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ExpressionStatementAST *_other = pattern->asExpressionStatement())
        return matcher->match(this, _other);

    return false;
}

bool FunctionDefinitionAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (FunctionDefinitionAST *_other = pattern->asFunctionDefinition())
        return matcher->match(this, _other);

    return false;
}

bool ForeachStatementAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ForeachStatementAST *_other = pattern->asForeachStatement())
        return matcher->match(this, _other);

    return false;
}

bool ForStatementAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ForStatementAST *_other = pattern->asForStatement())
        return matcher->match(this, _other);

    return false;
}

bool IfStatementAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (IfStatementAST *_other = pattern->asIfStatement())
        return matcher->match(this, _other);

    return false;
}

bool ArrayInitializerAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ArrayInitializerAST *_other = pattern->asArrayInitializer())
        return matcher->match(this, _other);

    return false;
}

bool LabeledStatementAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (LabeledStatementAST *_other = pattern->asLabeledStatement())
        return matcher->match(this, _other);

    return false;
}

bool LinkageBodyAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (LinkageBodyAST *_other = pattern->asLinkageBody())
        return matcher->match(this, _other);

    return false;
}

bool LinkageSpecificationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (LinkageSpecificationAST *_other = pattern->asLinkageSpecification())
        return matcher->match(this, _other);

    return false;
}

bool MemInitializerAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (MemInitializerAST *_other = pattern->asMemInitializer())
        return matcher->match(this, _other);

    return false;
}

bool NestedNameSpecifierAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (NestedNameSpecifierAST *_other = pattern->asNestedNameSpecifier())
        return matcher->match(this, _other);

    return false;
}

bool QualifiedNameAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (QualifiedNameAST *_other = pattern->asQualifiedName())
        return matcher->match(this, _other);

    return false;
}

bool OperatorFunctionIdAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (OperatorFunctionIdAST *_other = pattern->asOperatorFunctionId())
        return matcher->match(this, _other);

    return false;
}

bool ConversionFunctionIdAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ConversionFunctionIdAST *_other = pattern->asConversionFunctionId())
        return matcher->match(this, _other);

    return false;
}

bool SimpleNameAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (SimpleNameAST *_other = pattern->asSimpleName())
        return matcher->match(this, _other);

    return false;
}

bool DestructorNameAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (DestructorNameAST *_other = pattern->asDestructorName())
        return matcher->match(this, _other);

    return false;
}

bool TemplateIdAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (TemplateIdAST *_other = pattern->asTemplateId())
        return matcher->match(this, _other);

    return false;
}

bool NamespaceAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (NamespaceAST *_other = pattern->asNamespace())
        return matcher->match(this, _other);

    return false;
}

bool NamespaceAliasDefinitionAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (NamespaceAliasDefinitionAST *_other = pattern->asNamespaceAliasDefinition())
        return matcher->match(this, _other);

    return false;
}

bool NewPlacementAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (NewPlacementAST *_other = pattern->asNewPlacement())
        return matcher->match(this, _other);

    return false;
}

bool NewArrayDeclaratorAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (NewArrayDeclaratorAST *_other = pattern->asNewArrayDeclarator())
        return matcher->match(this, _other);

    return false;
}

bool NewExpressionAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (NewExpressionAST *_other = pattern->asNewExpression())
        return matcher->match(this, _other);

    return false;
}

bool NewInitializerAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (NewInitializerAST *_other = pattern->asNewInitializer())
        return matcher->match(this, _other);

    return false;
}

bool NewTypeIdAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (NewTypeIdAST *_other = pattern->asNewTypeId())
        return matcher->match(this, _other);

    return false;
}

bool OperatorAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (OperatorAST *_other = pattern->asOperator())
        return matcher->match(this, _other);

    return false;
}

bool ParameterDeclarationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ParameterDeclarationAST *_other = pattern->asParameterDeclaration())
        return matcher->match(this, _other);

    return false;
}

bool ParameterDeclarationClauseAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ParameterDeclarationClauseAST *_other = pattern->asParameterDeclarationClause())
        return matcher->match(this, _other);

    return false;
}

bool CallAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (CallAST *_other = pattern->asCall())
        return matcher->match(this, _other);

    return false;
}

bool ArrayAccessAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ArrayAccessAST *_other = pattern->asArrayAccess())
        return matcher->match(this, _other);

    return false;
}

bool PostIncrDecrAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (PostIncrDecrAST *_other = pattern->asPostIncrDecr())
        return matcher->match(this, _other);

    return false;
}

bool MemberAccessAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (MemberAccessAST *_other = pattern->asMemberAccess())
        return matcher->match(this, _other);

    return false;
}

bool TypeidExpressionAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (TypeidExpressionAST *_other = pattern->asTypeidExpression())
        return matcher->match(this, _other);

    return false;
}

bool TypenameCallExpressionAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (TypenameCallExpressionAST *_other = pattern->asTypenameCallExpression())
        return matcher->match(this, _other);

    return false;
}

bool TypeConstructorCallAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (TypeConstructorCallAST *_other = pattern->asTypeConstructorCall())
        return matcher->match(this, _other);

    return false;
}

bool PostfixExpressionAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (PostfixExpressionAST *_other = pattern->asPostfixExpression())
        return matcher->match(this, _other);

    return false;
}

bool PointerToMemberAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (PointerToMemberAST *_other = pattern->asPointerToMember())
        return matcher->match(this, _other);

    return false;
}

bool PointerAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (PointerAST *_other = pattern->asPointer())
        return matcher->match(this, _other);

    return false;
}

bool ReferenceAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ReferenceAST *_other = pattern->asReference())
        return matcher->match(this, _other);

    return false;
}

bool BreakStatementAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (BreakStatementAST *_other = pattern->asBreakStatement())
        return matcher->match(this, _other);

    return false;
}

bool ContinueStatementAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ContinueStatementAST *_other = pattern->asContinueStatement())
        return matcher->match(this, _other);

    return false;
}

bool GotoStatementAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (GotoStatementAST *_other = pattern->asGotoStatement())
        return matcher->match(this, _other);

    return false;
}

bool ReturnStatementAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ReturnStatementAST *_other = pattern->asReturnStatement())
        return matcher->match(this, _other);

    return false;
}

bool SizeofExpressionAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (SizeofExpressionAST *_other = pattern->asSizeofExpression())
        return matcher->match(this, _other);

    return false;
}

bool NumericLiteralAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (NumericLiteralAST *_other = pattern->asNumericLiteral())
        return matcher->match(this, _other);

    return false;
}

bool BoolLiteralAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (BoolLiteralAST *_other = pattern->asBoolLiteral())
        return matcher->match(this, _other);

    return false;
}

bool ThisExpressionAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ThisExpressionAST *_other = pattern->asThisExpression())
        return matcher->match(this, _other);

    return false;
}

bool NestedExpressionAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (NestedExpressionAST *_other = pattern->asNestedExpression())
        return matcher->match(this, _other);

    return false;
}

bool StringLiteralAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (StringLiteralAST *_other = pattern->asStringLiteral())
        return matcher->match(this, _other);

    return false;
}

bool SwitchStatementAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (SwitchStatementAST *_other = pattern->asSwitchStatement())
        return matcher->match(this, _other);

    return false;
}

bool TemplateDeclarationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (TemplateDeclarationAST *_other = pattern->asTemplateDeclaration())
        return matcher->match(this, _other);

    return false;
}

bool ThrowExpressionAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ThrowExpressionAST *_other = pattern->asThrowExpression())
        return matcher->match(this, _other);

    return false;
}

bool TranslationUnitAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (TranslationUnitAST *_other = pattern->asTranslationUnit())
        return matcher->match(this, _other);

    return false;
}

bool TryBlockStatementAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (TryBlockStatementAST *_other = pattern->asTryBlockStatement())
        return matcher->match(this, _other);

    return false;
}

bool CatchClauseAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (CatchClauseAST *_other = pattern->asCatchClause())
        return matcher->match(this, _other);

    return false;
}

bool TypeIdAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (TypeIdAST *_other = pattern->asTypeId())
        return matcher->match(this, _other);

    return false;
}

bool TypenameTypeParameterAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (TypenameTypeParameterAST *_other = pattern->asTypenameTypeParameter())
        return matcher->match(this, _other);

    return false;
}

bool TemplateTypeParameterAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (TemplateTypeParameterAST *_other = pattern->asTemplateTypeParameter())
        return matcher->match(this, _other);

    return false;
}

bool UnaryExpressionAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (UnaryExpressionAST *_other = pattern->asUnaryExpression())
        return matcher->match(this, _other);

    return false;
}

bool UsingAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (UsingAST *_other = pattern->asUsing())
        return matcher->match(this, _other);

    return false;
}

bool UsingDirectiveAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (UsingDirectiveAST *_other = pattern->asUsingDirective())
        return matcher->match(this, _other);

    return false;
}

bool WhileStatementAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (WhileStatementAST *_other = pattern->asWhileStatement())
        return matcher->match(this, _other);

    return false;
}

bool ObjCClassForwardDeclarationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCClassForwardDeclarationAST *_other = pattern->asObjCClassForwardDeclaration())
        return matcher->match(this, _other);

    return false;
}

bool ObjCClassDeclarationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCClassDeclarationAST *_other = pattern->asObjCClassDeclaration())
        return matcher->match(this, _other);

    return false;
}

bool ObjCProtocolForwardDeclarationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCProtocolForwardDeclarationAST *_other = pattern->asObjCProtocolForwardDeclaration())
        return matcher->match(this, _other);

    return false;
}

bool ObjCProtocolDeclarationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCProtocolDeclarationAST *_other = pattern->asObjCProtocolDeclaration())
        return matcher->match(this, _other);

    return false;
}

bool ObjCProtocolRefsAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCProtocolRefsAST *_other = pattern->asObjCProtocolRefs())
        return matcher->match(this, _other);

    return false;
}

bool ObjCMessageArgumentAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCMessageArgumentAST *_other = pattern->asObjCMessageArgument())
        return matcher->match(this, _other);

    return false;
}

bool ObjCMessageExpressionAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCMessageExpressionAST *_other = pattern->asObjCMessageExpression())
        return matcher->match(this, _other);

    return false;
}

bool ObjCProtocolExpressionAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCProtocolExpressionAST *_other = pattern->asObjCProtocolExpression())
        return matcher->match(this, _other);

    return false;
}

bool ObjCTypeNameAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCTypeNameAST *_other = pattern->asObjCTypeName())
        return matcher->match(this, _other);

    return false;
}

bool ObjCEncodeExpressionAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCEncodeExpressionAST *_other = pattern->asObjCEncodeExpression())
        return matcher->match(this, _other);

    return false;
}

bool ObjCSelectorWithoutArgumentsAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCSelectorWithoutArgumentsAST *_other = pattern->asObjCSelectorWithoutArguments())
        return matcher->match(this, _other);

    return false;
}

bool ObjCSelectorArgumentAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCSelectorArgumentAST *_other = pattern->asObjCSelectorArgument())
        return matcher->match(this, _other);

    return false;
}

bool ObjCSelectorWithArgumentsAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCSelectorWithArgumentsAST *_other = pattern->asObjCSelectorWithArguments())
        return matcher->match(this, _other);

    return false;
}

bool ObjCSelectorExpressionAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCSelectorExpressionAST *_other = pattern->asObjCSelectorExpression())
        return matcher->match(this, _other);

    return false;
}

bool ObjCInstanceVariablesDeclarationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCInstanceVariablesDeclarationAST *_other = pattern->asObjCInstanceVariablesDeclaration())
        return matcher->match(this, _other);

    return false;
}

bool ObjCVisibilityDeclarationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCVisibilityDeclarationAST *_other = pattern->asObjCVisibilityDeclaration())
        return matcher->match(this, _other);

    return false;
}

bool ObjCPropertyAttributeAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCPropertyAttributeAST *_other = pattern->asObjCPropertyAttribute())
        return matcher->match(this, _other);

    return false;
}

bool ObjCPropertyDeclarationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCPropertyDeclarationAST *_other = pattern->asObjCPropertyDeclaration())
        return matcher->match(this, _other);

    return false;
}

bool ObjCMessageArgumentDeclarationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCMessageArgumentDeclarationAST *_other = pattern->asObjCMessageArgumentDeclaration())
        return matcher->match(this, _other);

    return false;
}

bool ObjCMethodPrototypeAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCMethodPrototypeAST *_other = pattern->asObjCMethodPrototype())
        return matcher->match(this, _other);

    return false;
}

bool ObjCMethodDeclarationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCMethodDeclarationAST *_other = pattern->asObjCMethodDeclaration())
        return matcher->match(this, _other);

    return false;
}

bool ObjCSynthesizedPropertyAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCSynthesizedPropertyAST *_other = pattern->asObjCSynthesizedProperty())
        return matcher->match(this, _other);

    return false;
}

bool ObjCSynthesizedPropertiesDeclarationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCSynthesizedPropertiesDeclarationAST *_other = pattern->asObjCSynthesizedPropertiesDeclaration())
        return matcher->match(this, _other);

    return false;
}

bool ObjCDynamicPropertiesDeclarationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCDynamicPropertiesDeclarationAST *_other = pattern->asObjCDynamicPropertiesDeclaration())
        return matcher->match(this, _other);

    return false;
}

bool ObjCFastEnumerationAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCFastEnumerationAST *_other = pattern->asObjCFastEnumeration())
        return matcher->match(this, _other);

    return false;
}

bool ObjCSynchronizedStatementAST::match0(AST *pattern, ASTMatcher *matcher)
{
    if (ObjCSynchronizedStatementAST *_other = pattern->asObjCSynchronizedStatement())
        return matcher->match(this, _other);

    return false;
}


//========= Copyright Valve Corporation, All rights reserved. ============//
//                       TOGL CODE LICENSE
//
//  Copyright 2011-2014 Valve Corporation
//  All Rights Reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
// !!! FIXME: Some of these aren't base OpenGL...pick out the extensions.
// !!! FIXME: Also, look up these -1, -1 versions numbers.
GL_FUNC(OpenGL, true, GLenum, glGetError, (void), ())
GL_FUNC_VOID(OpenGL, true, glActiveTexture, (GLenum a), (a))
GL_FUNC_VOID(OpenGL, true, glAlphaFunc, (GLenum a, GLclampf b), (a, b))
GL_FUNC_VOID(OpenGL, true, glAttachObjectARB, (GLhandleARB a, GLhandleARB b), (a, b))
GL_FUNC_VOID(OpenGL, true, glBegin, (GLenum a), (a))
GL_FUNC_VOID(OpenGL, true, glBindAttribLocationARB, (GLhandleARB a, GLuint b, const GLcharARB *c), (a, b, c))
GL_FUNC_VOID(OpenGL, true, glBindBufferARB, (GLenum a, GLuint b), (a, b))
GL_FUNC_VOID(OpenGL, true, glBindProgramARB, (GLenum a, GLuint b), (a, b))
GL_FUNC_VOID(OpenGL, true, glBindTexture, (GLenum a, GLuint b), (a, b))
GL_FUNC_VOID(OpenGL, true, glBlendColor, (GLclampf a, GLclampf b, GLclampf c, GLclampf d), (a, b, c, d))
GL_FUNC_VOID(OpenGL, true, glBlendEquation, (GLenum a), (a))
GL_FUNC_VOID(OpenGL, true, glBlendFunc, (GLenum a, GLenum b), (a, b))
GL_FUNC_VOID(OpenGL, true, glBufferDataARB, (GLenum a, GLsizeiptrARB b, const GLvoid *c, GLenum d), (a, b, c, d))
GL_FUNC_VOID(OpenGL, true, glClear, (GLbitfield a), (a))
GL_FUNC_VOID(OpenGL, true, glClearColor, (GLclampf a, GLclampf b, GLclampf c, GLclampf d), (a, b, c, d))
GL_FUNC_VOID(OpenGL, true, glClearDepth, (GLclampd a), (a))
GL_FUNC_VOID(OpenGL, true, glClearStencil, (GLint a), (a))
GL_FUNC_VOID(OpenGL, true, glClipPlane, (GLenum a, const GLdouble *b), (a, b))
GL_FUNC_VOID(OpenGL, true, glColorMask, (GLboolean a, GLboolean b, GLboolean c, GLboolean d), (a, b, c, d))
GL_FUNC_VOID(OpenGL, true, glCompileShaderARB, (GLhandleARB a), (a))
GL_FUNC_VOID(OpenGL, true, glCompressedTexImage2D,
			 (GLenum a, GLint b, GLenum c, GLsizei d, GLsizei e, GLint f, GLsizei g, const GLvoid *h),
			 (a, b, c, d, e, f, g, h))
GL_FUNC_VOID(OpenGL, true, glCompressedTexImage3D,
			 (GLenum a, GLint b, GLenum c, GLsizei d, GLsizei e, GLsizei f, GLint g, GLsizei h, const GLvoid *i),
			 (a, b, c, d, e, f, g, h, i))
GL_FUNC(OpenGL, true, GLhandleARB, glCreateProgramObjectARB, (void), ())
GL_FUNC(OpenGL, true, GLhandleARB, glCreateShaderObjectARB, (GLenum a), (a))
GL_FUNC_VOID(OpenGL, true, glDeleteBuffersARB, (GLsizei a, const GLuint *b), (a, b))
GL_FUNC_VOID(OpenGL, true, glDeleteObjectARB, (GLhandleARB a), (a))
GL_FUNC_VOID(OpenGL, true, glDeleteProgramsARB, (GLsizei a, const GLuint *b), (a, b))
GL_FUNC_VOID(OpenGL, true, glDeleteQueriesARB, (GLsizei a, const GLuint *b), (a, b))
GL_FUNC_VOID(OpenGL, true, glDeleteShader, (GLuint a), (a))
GL_FUNC_VOID(OpenGL, true, glDeleteTextures, (GLsizei a, const GLuint *b), (a, b))
GL_FUNC_VOID(OpenGL, true, glDepthFunc, (GLenum a), (a))
GL_FUNC_VOID(OpenGL, true, glDepthMask, (GLboolean a), (a))
GL_FUNC_VOID(OpenGL, true, glDepthRange, (GLclampd a, GLclampd b), (a, b))
GL_FUNC_VOID(OpenGL, true, glDetachObjectARB, (GLhandleARB a, GLhandleARB b), (a, b))
GL_FUNC_VOID(OpenGL, true, glDisable, (GLenum a), (a))
GL_FUNC_VOID(OpenGL, true, glDisableVertexAttribArray, (GLuint a), (a))
GL_FUNC_VOID(OpenGL, true, glDrawArrays, (GLenum a, GLint b, GLsizei c), (a, b, c))
GL_FUNC_VOID(OpenGL, true, glDrawBuffer, (GLenum a), (a))
GL_FUNC_VOID(OpenGL, true, glDrawBuffers, (GLsizei a, const GLenum *b), (a, b))
GL_FUNC_VOID(OpenGL, true, glDrawRangeElements, (GLenum a, GLuint b, GLuint c, GLsizei d, GLenum e, const GLvoid *f),
			 (a, b, c, d, e, f))
#ifndef OSX // 10.6/GL 2.1 compatability
GL_FUNC_VOID(OpenGL, true, glDrawRangeElementsBaseVertex,
			 (GLenum a, GLuint b, GLuint c, GLsizei d, GLenum e, const GLvoid *f, GLenum g), (a, b, c, d, e, f, g))
#endif
GL_FUNC_VOID(OpenGL, true, glEnable, (GLenum a), (a))
GL_FUNC_VOID(OpenGL, true, glEnableVertexAttribArray, (GLuint a), (a))
GL_FUNC_VOID(OpenGL, true, glEnd, (void), ())
GL_FUNC_VOID(OpenGL, true, glFinish, (void), ())
GL_FUNC_VOID(OpenGL, true, glFlush, (void), ())
GL_FUNC_VOID(OpenGL, true, glFrontFace, (GLenum a), (a))
GL_FUNC_VOID(OpenGL, true, glGenBuffersARB, (GLsizei a, GLuint *b), (a, b))
GL_FUNC_VOID(OpenGL, true, glGenProgramsARB, (GLsizei a, GLuint *b), (a, b))
GL_FUNC_VOID(OpenGL, true, glGenQueriesARB, (GLsizei a, GLuint *b), (a, b))
GL_FUNC_VOID(OpenGL, true, glGenTextures, (GLsizei a, GLuint *b), (a, b))
GL_FUNC_VOID(OpenGL, true, glGetBooleanv, (GLenum a, GLboolean *b), (a, b))
GL_FUNC_VOID(OpenGL, true, glGetCompressedTexImage, (GLenum a, GLint b, GLvoid *c), (a, b, c))
GL_FUNC_VOID(OpenGL, true, glGetDoublev, (GLenum a, GLdouble *b), (a, b))
GL_FUNC_VOID(OpenGL, true, glGetFloatv, (GLenum a, GLfloat *b), (a, b))
GL_FUNC_VOID(OpenGL, true, glGetInfoLogARB, (GLhandleARB a, GLsizei b, GLsizei *c, GLcharARB *d), (a, b, c, d))
GL_FUNC_VOID(OpenGL, true, glGetIntegerv, (GLenum a, GLint *b), (a, b))
GL_FUNC_VOID(OpenGL, true, glGetObjectParameterivARB, (GLhandleARB a, GLenum b, GLint *c), (a, b, c))
GL_FUNC_VOID(OpenGL, true, glGetProgramivARB, (GLenum a, GLenum b, GLint *c), (a, b, c))
GL_FUNC(OpenGL, true, const GLubyte *, glGetString, (GLenum a), (a))
GL_FUNC_VOID(OpenGL, true, glGetTexImage, (GLenum a, GLint b, GLenum c, GLenum d, GLvoid *e), (a, b, c, d, e))
GL_FUNC(OpenGL, true, GLint, glGetUniformLocationARB, (GLhandleARB a, const GLcharARB *b), (a, b))
GL_FUNC(OpenGL, true, GLboolean, glIsEnabled, (GLenum a), (a))
GL_FUNC(OpenGL, true, GLboolean, glIsTexture, (GLuint a), (a))
GL_FUNC_VOID(OpenGL, true, glLinkProgramARB, (GLhandleARB a), (a))
GL_FUNC(OpenGL, true, GLvoid *, glMapBufferARB, (GLenum a, GLenum b), (a, b))
GL_FUNC_VOID(OpenGL, true, glOrtho, (GLdouble a, GLdouble b, GLdouble c, GLdouble d, GLdouble e, GLdouble f),
			 (a, b, c, d, e, f))
GL_FUNC_VOID(OpenGL, true, glPixelStorei, (GLenum a, GLint b), (a, b))
GL_FUNC_VOID(OpenGL, true, glPolygonMode, (GLenum a, GLenum b), (a, b))
GL_FUNC_VOID(OpenGL, true, glPolygonOffset, (GLfloat a, GLfloat b), (a, b))
GL_FUNC_VOID(OpenGL, true, glPopAttrib, (void), ())
GL_FUNC_VOID(OpenGL, true, glProgramStringARB, (GLenum a, GLenum b, GLsizei c, const GLvoid *d), (a, b, c, d))
GL_FUNC_VOID(OpenGL, true, glPushAttrib, (GLbitfield a), (a))
GL_FUNC_VOID(OpenGL, true, glReadBuffer, (GLenum a), (a))
GL_FUNC_VOID(OpenGL, true, glScissor, (GLint a, GLint b, GLsizei c, GLsizei d), (a, b, c, d))
GL_FUNC_VOID(OpenGL, true, glShaderSourceARB, (GLhandleARB a, GLsizei b, const GLcharARB **c, const GLint *d),
			 (a, b, c, d))
GL_FUNC_VOID(OpenGL, true, glStencilFunc, (GLenum a, GLint b, GLuint c), (a, b, c))
GL_FUNC_VOID(OpenGL, true, glStencilMask, (GLuint a), (a))
GL_FUNC_VOID(OpenGL, true, glStencilOp, (GLenum a, GLenum b, GLenum c), (a, b, c))
GL_FUNC_VOID(OpenGL, true, glTexCoord2f, (GLfloat a, GLfloat b), (a, b))
GL_FUNC_VOID(OpenGL, true, glTexImage2D,
			 (GLenum a, GLint b, GLint c, GLsizei d, GLsizei e, GLint f, GLenum g, GLenum h, const GLvoid *i),
			 (a, b, c, d, e, f, g, h, i))
GL_FUNC_VOID(OpenGL, true, glTexImage3D,
			 (GLenum a, GLint b, GLint c, GLsizei d, GLsizei e, GLsizei f, GLint g, GLenum h, GLenum i,
			  const GLvoid *j),
			 (a, b, c, d, e, f, g, h, i, j))
GL_FUNC_VOID(OpenGL, true, glTexParameterfv, (GLenum a, GLenum b, const GLfloat *c), (a, b, c))
GL_FUNC_VOID(OpenGL, true, glTexParameteri, (GLenum a, GLenum b, GLint c), (a, b, c))
GL_FUNC_VOID(OpenGL, true, glTexSubImage2D,
			 (GLenum a, GLint b, GLint c, GLint d, GLsizei e, GLsizei f, GLenum g, GLenum h, const GLvoid *i),
			 (a, b, c, d, e, f, g, h, i))
GL_FUNC_VOID(OpenGL, true, glUniform1f, (GLint a, GLfloat b), (a, b))
GL_FUNC_VOID(OpenGL, true, glUniform1i, (GLint a, GLint b), (a, b))
GL_FUNC_VOID(OpenGL, true, glUniform1iARB, (GLint a, GLint b), (a, b))
GL_FUNC_VOID(OpenGL, true, glUniform4fv, (GLint a, GLsizei b, const GLfloat *c), (a, b, c))
GL_FUNC(OpenGL, true, GLboolean, glUnmapBuffer, (GLenum a), (a))
GL_FUNC_VOID(OpenGL, true, glUseProgram, (GLuint a), (a))
GL_FUNC_VOID(OpenGL, true, glVertex3f, (GLfloat a, GLfloat b, GLfloat c), (a, b, c))
GL_FUNC_VOID(OpenGL, true, glVertexAttribPointer,
			 (GLuint a, GLint b, GLenum c, GLboolean d, GLsizei e, const GLvoid *f), (a, b, c, d, e, f))
GL_FUNC_VOID(OpenGL, true, glViewport, (GLint a, GLint b, GLsizei c, GLsizei d), (a, b, c, d))
GL_FUNC_VOID(OpenGL, true, glEnableClientState, (GLenum a), (a))
GL_FUNC_VOID(OpenGL, true, glDisableClientState, (GLenum a), (a))
GL_FUNC_VOID(OpenGL, true, glClientActiveTexture, (GLenum a), (a))
GL_FUNC_VOID(OpenGL, true, glVertexPointer, (GLint a, GLenum b, GLsizei c, const GLvoid *d), (a, b, c, d))
GL_FUNC_VOID(OpenGL, true, glTexCoordPointer, (GLint a, GLenum b, GLsizei c, const GLvoid *d), (a, b, c, d))
GL_FUNC_VOID(OpenGL, true, glProgramEnvParameters4fvEXT, (GLenum a, GLuint b, GLsizei c, const GLfloat *d),
			 (a, b, c, d))
GL_FUNC_VOID(OpenGL, true, glColor4sv, (const GLshort *a), (a))
GL_FUNC_VOID(OpenGL, true, glStencilOpSeparate, (GLenum a, GLenum b, GLenum c, GLenum d), (a, b, c, d))
GL_FUNC_VOID(OpenGL, true, glStencilFuncSeparate, (GLenum a, GLenum b, GLint c, GLuint d), (a, b, c, d))
GL_FUNC_VOID(OpenGL, true, glGetTexLevelParameteriv, (GLenum a, GLint b, GLenum c, GLint *d), (a, b, c, d))
GL_FUNC_VOID(OpenGL, true, glColor4f, (GLfloat a, GLfloat b, GLfloat c, GLfloat d), (a, b, c, d))
GL_EXT(GL_EXT_framebuffer_object, -1, -1)
GL_FUNC_VOID(GL_EXT_framebuffer_object, false, glBindFramebufferEXT, (GLenum a, GLuint b), (a, b))
GL_FUNC_VOID(GL_EXT_framebuffer_object, false, glBindRenderbufferEXT, (GLenum a, GLuint b), (a, b))
GL_FUNC(GL_EXT_framebuffer_object, false, GLenum, glCheckFramebufferStatusEXT, (GLenum a), (a))
GL_FUNC_VOID(GL_EXT_framebuffer_object, false, glDeleteRenderbuffersEXT, (GLsizei a, const GLuint *b), (a, b))
GL_FUNC_VOID(GL_EXT_framebuffer_object, false, glFramebufferRenderbufferEXT, (GLenum a, GLenum b, GLenum c, GLuint d),
			 (a, b, c, d))
GL_FUNC_VOID(GL_EXT_framebuffer_object, false, glFramebufferTexture2DEXT,
			 (GLenum a, GLenum b, GLenum c, GLuint d, GLint e), (a, b, c, d, e))
GL_FUNC_VOID(GL_EXT_framebuffer_object, false, glFramebufferTexture3DEXT,
			 (GLenum a, GLenum b, GLenum c, GLuint d, GLint e, GLint f), (a, b, c, d, e, f))
GL_FUNC_VOID(GL_EXT_framebuffer_object, false, glGenFramebuffersEXT, (GLsizei a, GLuint *b), (a, b))
GL_FUNC_VOID(GL_EXT_framebuffer_object, false, glGenRenderbuffersEXT, (GLsizei a, GLuint *b), (a, b))
GL_FUNC_VOID(GL_EXT_framebuffer_object, false, glDeleteFramebuffersEXT, (GLsizei a, const GLuint *b), (a, b))
GL_EXT(GL_EXT_framebuffer_blit, -1, -1)
GL_FUNC_VOID(GL_EXT_framebuffer_blit, false, glBlitFramebufferEXT,
			 (GLint a, GLint b, GLint c, GLint d, GLint e, GLint f, GLint g, GLint h, GLbitfield i, GLenum j),
			 (a, b, c, d, e, f, g, h, i, j))
GL_EXT(GL_EXT_framebuffer_multisample, -1, -1)
GL_FUNC_VOID(GL_EXT_framebuffer_multisample, false, glRenderbufferStorageMultisampleEXT,
			 (GLenum a, GLsizei b, GLenum c, GLsizei d, GLsizei e), (a, b, c, d, e))
GL_EXT(GL_APPLE_fence, -1, -1)
GL_FUNC(GL_APPLE_fence, false, GLboolean, glTestFenceAPPLE, (GLuint a), (a))
GL_FUNC_VOID(GL_APPLE_fence, false, glSetFenceAPPLE, (GLuint a), (a))
GL_FUNC_VOID(GL_APPLE_fence, false, glFinishFenceAPPLE, (GLuint a), (a))
GL_FUNC_VOID(GL_APPLE_fence, false, glDeleteFencesAPPLE, (GLsizei a, const GLuint *b), (a, b))
GL_FUNC_VOID(GL_APPLE_fence, false, glGenFencesAPPLE, (GLsizei a, GLuint *b), (a, b))
GL_EXT(GL_NV_fence, -1, -1)
GL_FUNC(GL_NV_fence, false, GLboolean, glTestFenceNV, (GLuint a), (a))
GL_FUNC_VOID(GL_NV_fence, false, glSetFenceNV, (GLuint a, GLenum b), (a, b))
GL_FUNC_VOID(GL_NV_fence, false, glFinishFenceNV, (GLuint a), (a))
GL_FUNC_VOID(GL_NV_fence, false, glDeleteFencesNV, (GLsizei a, const GLuint *b), (a, b))
GL_FUNC_VOID(GL_NV_fence, false, glGenFencesNV, (GLsizei a, GLuint *b), (a, b))
GL_EXT(GL_ARB_sync, 3, 2)
#ifdef HAVE_GL_ARB_SYNC
GL_FUNC_VOID(GL_ARB_sync, false, glGetSynciv, (GLsync a, GLenum b, GLsizei c, GLsizei *d, GLint *e), (a, b, c, d, e))
GL_FUNC(GL_ARB_sync, false, GLenum, glClientWaitSync, (GLsync a, GLbitfield b, GLuint64 c), (a, b, c))
GL_FUNC_VOID(GL_ARB_sync, false, glWaitSync, (GLsync a, GLbitfield b, GLuint64 c), (a, b, c))
GL_FUNC_VOID(GL_ARB_sync, false, glDeleteSync, (GLsync a), (a))
GL_FUNC(GL_ARB_sync, false, GLsync, glFenceSync, (GLenum a, GLbitfield b), (a, b))
#endif
GL_EXT(GL_EXT_draw_buffers2, -1, -1)
GL_FUNC_VOID(GL_EXT_draw_buffers2, true, glColorMaskIndexedEXT,
			 (GLuint a, GLboolean b, GLboolean c, GLboolean d, GLboolean e), (a, b, c, d, e))
GL_FUNC_VOID(GL_EXT_draw_buffers2, true, glEnableIndexedEXT, (GLenum a, GLuint b), (a, b))
GL_FUNC_VOID(GL_EXT_draw_buffers2, true, glDisableIndexedEXT, (GLenum a, GLuint b), (a, b))
GL_FUNC_VOID(GL_EXT_draw_buffers2, true, glGetBooleanIndexedvEXT, (GLenum a, GLuint b, GLboolean *c), (a, b, c))
GL_EXT(GL_EXT_bindable_uniform, -1, -1)
GL_FUNC_VOID(GL_EXT_bindable_uniform, false, glUniformBufferEXT, (GLuint a, GLint b, GLuint c), (a, b, c))
GL_FUNC(GL_EXT_bindable_uniform, false, int, glGetUniformBufferSizeEXT, (GLenum a, GLenum b), (a, b))
GL_FUNC(GL_EXT_bindable_uniform, false, GLintptr, glGetUniformOffsetEXT, (GLenum a, GLenum b), (a, b))
GL_EXT(GL_APPLE_flush_buffer_range, -1, -1)
GL_FUNC_VOID(GL_APPLE_flush_buffer_range, false, glBufferParameteriAPPLE, (GLenum a, GLenum b, GLint c), (a, b, c))
GL_FUNC_VOID(GL_APPLE_flush_buffer_range, false, glFlushMappedBufferRangeAPPLE, (GLenum a, GLintptr b, GLsizeiptr c),
			 (a, b, c))
GL_EXT(GL_ARB_map_buffer_range, -1, -1)
GL_FUNC(GL_ARB_map_buffer_range, false, void *, glMapBufferRange, (GLenum a, GLintptr b, GLsizeiptr c, GLbitfield d),
		(a, b, c, d))
GL_FUNC_VOID(GL_ARB_map_buffer_range, false, glFlushMappedBufferRange, (GLenum a, GLintptr b, GLsizeiptr c), (a, b, c))
GL_EXT(GL_ARB_vertex_buffer_object, -1, -1)
GL_FUNC_VOID(GL_ARB_vertex_buffer_object, true, glBufferSubData, (GLenum a, GLintptr b, GLsizeiptr c, const GLvoid *d),
			 (a, b, c, d))
GL_EXT(GL_ARB_occlusion_query, -1, -1)
GL_FUNC_VOID(GL_ARB_occlusion_query, false, glBeginQueryARB, (GLenum a, GLuint b), (a, b))
GL_FUNC_VOID(GL_ARB_occlusion_query, false, glEndQueryARB, (GLenum a), (a))
GL_FUNC_VOID(GL_ARB_occlusion_query, false, glGetQueryObjectivARB, (GLuint a, GLenum b, GLint *c), (a, b, c))
GL_FUNC_VOID(GL_ARB_occlusion_query, false, glGetQueryObjectuivARB, (GLuint a, GLenum b, GLuint *c), (a, b, c))
GL_EXT(GL_APPLE_texture_range, -1, -1)
GL_FUNC_VOID(GL_APPLE_texture_range, false, glTextureRangeAPPLE, (GLenum a, GLsizei b, void *c), (a, b, c))
GL_FUNC_VOID(GL_APPLE_texture_range, false, glGetTexParameterPointervAPPLE, (GLenum a, GLenum b, void **c), (a, b, c))
GL_EXT(GL_APPLE_client_storage, -1, -1)
GL_EXT(GL_ARB_uniform_buffer, -1, -1)
GL_EXT(GL_ARB_vertex_array_bgra, -1, -1)
GL_EXT(GL_EXT_vertex_array_bgra, -1, -1)
GL_EXT(GL_ARB_framebuffer_object, 3, 0)
GL_FUNC_VOID(GL_ARB_framebuffer_object, false, glBindFramebuffer, (GLenum a, GLuint b), (a, b))
GL_FUNC_VOID(GL_ARB_framebuffer_object, false, glBindRenderbuffer, (GLenum a, GLuint b), (a, b))
GL_FUNC(GL_ARB_framebuffer_object, false, GLenum, glCheckFramebufferStatus, (GLenum a), (a))
GL_FUNC_VOID(GL_ARB_framebuffer_object, false, glDeleteRenderbuffers, (GLsizei a, const GLuint *b), (a, b))
GL_FUNC_VOID(GL_ARB_framebuffer_object, false, glFramebufferRenderbuffer, (GLenum a, GLenum b, GLenum c, GLuint d),
			 (a, b, c, d))
GL_FUNC_VOID(GL_ARB_framebuffer_object, false, glFramebufferTexture2D,
			 (GLenum a, GLenum b, GLenum c, GLuint d, GLint e), (a, b, c, d, e))
GL_FUNC_VOID(GL_ARB_framebuffer_object, false, glFramebufferTexture3D,
			 (GLenum a, GLenum b, GLenum c, GLuint d, GLint e, GLint f), (a, b, c, d, e, f))
GL_FUNC_VOID(GL_ARB_framebuffer_object, false, glGenFramebuffers, (GLsizei a, GLuint *b), (a, b))
GL_FUNC_VOID(GL_ARB_framebuffer_object, false, glGenRenderbuffers, (GLsizei a, GLuint *b), (a, b))
GL_FUNC_VOID(GL_ARB_framebuffer_object, false, glDeleteFramebuffers, (GLsizei a, const GLuint *b), (a, b))
GL_FUNC_VOID(GL_ARB_framebuffer_object, false, glBlitFramebuffer,
			 (GLint a, GLint b, GLint c, GLint d, GLint e, GLint f, GLint g, GLint h, GLbitfield i, GLenum j),
			 (a, b, c, d, e, f, g, h, i, j))
GL_FUNC_VOID(GL_ARB_framebuffer_object, false, glRenderbufferStorageMultisample,
			 (GLenum a, GLsizei b, GLenum c, GLsizei d, GLsizei e), (a, b, c, d, e))
GL_EXT(GL_GREMEDY_string_marker, -1, -1)
GL_FUNC_VOID(GL_GREMEDY_string_marker, false, glStringMarkerGREMEDY, (GLsizei a, const void *b), (a, b))
GL_EXT(GL_ARB_debug_output, -1, -1)
#ifdef OSX
GL_FUNC_VOID(GL_ARB_debug_output, false, glDebugMessageCallbackARB,
			 (void (*a)(GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar *, GLvoid *), void *b), (a, b))
#else
GL_FUNC_VOID(GL_ARB_debug_output, false, glDebugMessageCallbackARB,
			 (void(APIENTRY * a)(GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar *, GLvoid *), void *b), (a, b))
#endif
GL_FUNC_VOID(GL_ARB_debug_output, false, glDebugMessageControlARB,
			 (GLenum a, GLenum b, GLenum c, GLsizei d, const GLuint *e, GLboolean f), (a, b, c, d, e, f))

GL_EXT(GL_EXT_direct_state_access, -1, -1)
GL_FUNC_VOID(GL_EXT_direct_state_access, false, glBindMultiTextureEXT, (GLenum a, GLuint b, GLuint c), (a, b, c))
GL_EXT(GL_NV_bindless_texture, -1, -1)

#ifndef OSX
GL_FUNC_VOID(OpenGL, true, glGenSamplers, (GLuint a, GLuint *b), (a, b))
GL_FUNC_VOID(OpenGL, true, glDeleteSamplers, (GLsizei a, const GLuint *b), (a, b))
GL_FUNC_VOID(OpenGL, true, glBindSampler, (GLuint a, GLuint b), (a, b))
GL_FUNC_VOID(OpenGL, true, glSamplerParameteri, (GLuint a, GLenum b, GLint c), (a, b, c))
GL_FUNC_VOID(OpenGL, true, glSamplerParameterf, (GLuint a, GLenum b, GLfloat c), (a, b, c))
GL_FUNC_VOID(OpenGL, true, glSamplerParameterfv, (GLuint a, GLenum b, const GLfloat *c), (a, b, c))
GL_FUNC(GL_NV_bindless_texture, false, GLuint64, glGetTextureHandleNV, (GLuint texture), (texture))
GL_FUNC(GL_NV_bindless_texture, false, GLuint64, glGetTextureSamplerHandleNV, (GLuint texture, GLuint sampler),
		(texture, sampler))
GL_FUNC_VOID(GL_NV_bindless_texture, false, glMakeTextureHandleResidentNV, (GLuint64 handle), (handle))
GL_FUNC_VOID(GL_NV_bindless_texture, false, glMakeTextureHandleNonResidentNV, (GLuint64 handle), (handle))
GL_FUNC_VOID(GL_NV_bindless_texture, false, glUniformHandleui64NV, (GLint location, GLuint64 value), (location, value))
GL_FUNC_VOID(GL_NV_bindless_texture, false, glUniformHandleui64vNV,
			 (int location, GLsizei count, const GLuint64 *value), (location count, value))
GL_FUNC_VOID(GL_NV_bindless_texture, false, glProgramUniformHandleui64NV,
			 (GLuint program, GLint location, GLuint64 value), (program, location, value))
GL_FUNC_VOID(GL_NV_bindless_texture, false, glProgramUniformHandleui64vNV,
			 (GLuint program, GLint location, GLsizei count, const GLuint64 *values),
			 (program, location, count, values))
GL_FUNC(GL_NV_bindless_texture, false, GLboolean, glIsTextureHandleResidentNV, (GLuint64 handle), (handle))
GL_FUNC_VOID(OpenGL, true, glGenQueries, (GLsizei n, GLuint *ids), (n, ids))
GL_FUNC_VOID(OpenGL, true, glDeleteQueries, (GLsizei n, const GLuint *ids), (n, ids))
GL_FUNC_VOID(OpenGL, true, glBeginQuery, (GLenum target, GLuint id), (target, id))
GL_FUNC_VOID(OpenGL, true, glEndQuery, (GLenum target), (target))
GL_FUNC_VOID(OpenGL, true, glQueryCounter, (GLuint id, GLenum target), (id, target))
GL_FUNC_VOID(OpenGL, true, glGetQueryObjectiv, (GLuint id, GLenum pname, GLint *params), (id, pname, params))
GL_FUNC_VOID(OpenGL, true, glGetQueryObjectui64v, (GLuint id, GLenum pname, GLuint64 *params), (id, pname, params))
GL_FUNC_VOID(OpenGL, true, glCopyBufferSubData,
			 (GLenum readtarget, GLenum writetarget, GLintptr readoffset, GLintptr writeoffset, GLsizeiptr size),
			 (readtarget, writetarget, readoffset, writeoffset, size))
#endif // !OSX

GL_EXT(GL_AMD_pinned_memory, -1, -1)
GL_EXT(GL_EXT_framebuffer_multisample_blit_scaled, -1, -1)

#ifndef OSX
GL_FUNC_VOID(OpenGL, true, glGenVertexArrays, (GLsizei n, GLuint *arrays), (n, arrays))
GL_FUNC_VOID(OpenGL, true, glDeleteVertexArrays, (GLsizei n, GLuint *arrays), (n, arrays))
GL_FUNC_VOID(OpenGL, true, glBindVertexArray, (GLuint a), (a))
#endif // !OSX

GL_EXT(GL_EXT_texture_sRGB_decode, -1, -1)
GL_FUNC_VOID(OpenGL, true, glPushClientAttrib, (GLbitfield a), (a))
GL_FUNC_VOID(OpenGL, true, glPopClientAttrib, (void), ())
GL_EXT(GL_NVX_gpu_memory_info, -1, -1)
GL_EXT(GL_ATI_meminfo, -1, -1)
GL_EXT(GL_EXT_texture_compression_s3tc, -1, -1)
GL_EXT(GL_EXT_texture_compression_dxt1, -1, -1)
GL_EXT(GL_ANGLE_texture_compression_dxt3, -1, -1)
GL_EXT(GL_ANGLE_texture_compression_dxt5, -1, -1)

GL_EXT(GL_ARB_buffer_storage, 4, 4)
GL_FUNC_VOID(GL_ARB_buffer_storage, false, glBufferStorage,
			 (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags), (target, size, data, flags))

// This one is an OS extension. We'll add a little helper function to look for it.
#ifdef _WIN32
GL_EXT(WGL_EXT_swap_control_tear, -1, -1)
#else
GL_EXT(GLX_EXT_swap_control_tear, -1, -1)
#endif
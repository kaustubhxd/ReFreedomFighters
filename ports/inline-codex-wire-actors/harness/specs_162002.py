"""specs_s38076.py - cascade s8 batch 38076. thiscall(this, a, b) ret 8. this+0x44 -> object (slot 0x12c(handle, word)), this+0x1d0f (unaligned) -> notice object (0 sometimes). Engine table object: slot 0x138 -> Z (slot 0x88 writes a
value to its out pointer), slot 0x114 (5 args, writes an object pointer to its out pointer, returns a random dword), table +0xae4 -> text object (slot 0 pops two args). sys slot 0x190 -> formatter (slot 0x198 cdecl varargs writes a
text into the buffer). 0x5adeb0 (mask 0..255 random) / 0x5ae930 are custom hooks logging the buffer by content; 0x5a8510 is hooked. a in -3..0x2b (keys of the name table, -3..-1 and 0x28.. not found), b random (low byte often 0)."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec


def _cstr(em, p, lim=0x40):
    out = b''
    while len(out) < lim:
        b = em.rbytes(p, 1)
        if b == b'\0':
            break
        out += b
        p += 1
    return out


def _g597fc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ctxobj = rnd(c, 0x40)
    strs = []
    for s in (b'one', b'two words', b'three'):
        p = e.alloc(0x20, 1)
        e.wbytes(p, s + b'\0')
        strs.append(p)
    zval = r.getrandbits(32)

    def z88(em, res_):
        em.calllog.append(('z88', em.arg32(0)))
        em.w32(em.arg32(1), zval)
        em.ret(eax=0, argbytes=8)
    Z = obj(c, 0x20, {0x88: e.stub_fn('z88', z88)})

    def s114(em, res_):
        em.calllog.append(('s114', em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3)))
        em.w32(em.arg32(4), ctxobj)
        em.ret(eax=r.getrandbits(32), argbytes=20)

    def tx(em, res_):
        a0, a1 = em.arg32(0), em.arg32(1)
        em.calllog.append(('text', a0, a1))
        em.ret(eax=strs[(a1 // 4) % 3], argbytes=8)
    tb2 = obj(c, 0x20, {0: e.stub_fn('text', tx)})
    t138 = e.stub_fn('s138', lambda em, res_: (em.calllog.append(('s138',)), em.ret(eax=Z)))
    so = sysobj(c, table_size=0xb00, table_slots={0x138: t138, 0x114: e.stub_fn('s114', s114)}, slots={})

    def fm(em, res_):
        n = em.arg32(3)
        em.calllog.append(('fmt', em.arg32(0), em.arg32(2), n))
        em.wbytes(em.arg32(1), b'F%x\0' % (n & 0xffff))
        em.ret(eax=0, argbytes=0)
    F = obj(c, 0x20, {0x198: e.stub_fn('fmt', fm)})
    vt = e.r32(so)
    e.w32(vt + 0x190, e.stub_fn('s190', lambda em, res_: (em.calllog.append(('s190',)), em.ret(eax=F))))
    e.w32(e.r32(so + 0x9b) + 0xae4, tb2)
    o44 = obj(c, 0x20, {0x12c: e.stub_fn('s12c', lambda em, res_: (em.calllog.append(('s12c', em.reg('ecx'), em.arg32(0), em.arg32(1))), em.ret(eax=0, argbytes=8)))})
    this = rnd(c, 0x1d20)
    e.w32(this + 0x44, o44)
    e.wbytes(this + 0x1d0f, struct.pack('<I', rnd(c, 0x40) if r.random() > 0.15 else 0))

    def a5adeb0(em, res_):
        em.calllog.append(('5adeb0', em.reg('ecx'), _cstr(em, em.arg32(0))))
        em.ret(eax=r.getrandbits(32), argbytes=4)
    e.hook(0x5adeb0, a5adeb0)

    def a5ae930(em, res_):
        em.calllog.append(('5ae930', em.reg('ecx'), _cstr(em, em.arg32(0)), em.arg32(1)))
        em.ret(eax=0, argbytes=8)
    e.hook(0x5ae930, a5ae930)
    def notice(em, res_):
        em.calllog.append(('notice', em.reg('ecx'), em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=8)
    e.hook(0x5a8510, notice)
    a = r.randrange(-3, 0x2c)
    b = r.getrandbits(32)
    if r.random() < 0.5:
        b &= ~0xff
    return [this, a, b]


S(0x597fc0, 'ZGameOSD::HintMessage seen-mask and table dispatch', 'thiscall', None, ret=None, gen=_g597fc0, reg_values=True, note='batch162002: strengthened exact heap receivers, out-pointer values consumed, buffers compared by content; callee stand-ins explicit')

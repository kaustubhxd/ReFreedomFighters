"""specs_s8841.py - residue 6 batch 88. GUESS names. Callees and vtable slots hooked by address.
0x65f1e0 (stdcall, ret 8): [p+0x24] |= 1; [p+0x40] = f (float).
0x5335a0 (thiscall, ret 4): r = vcall(this, 0x244, a); returns r ? *(u32*)r : 0.
0x433420 (thiscall, ret 4): [this+0xf8] = a; returns 0x431410(0x67a048, a) (thiscall, ret 8).
0x448be0 (thiscall, ret 4): 0x448a30(this, a); 0x4e1b30(a); returns 0.
0x427120 (cdecl, ret=eax:edx): calls [0x676124] with &local (8 bytes).
"""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_f1e0(c):
    # 0x65f1e0: stdcall(p, f) - needs a buffer p and a float f
    p = _rnd(c, 0x50)  # Allocate buffer with space for +0x24 and +0x40
    f = c.rng.random()  # Random float
    return [p, f]


def _gen_5335a0(c):
    # 0x5335a0: thiscall(a) - needs this with a vtable and an argument a
    e = c.emu

    # Generate return value for the vcall
    should_return_ptr = c.rng.random() < 0.5
    if should_return_ptr:
        r_ptr = _rnd(c, 0x20)
        r_val = c.rng.getrandbits(32)
        e.w32(r_ptr, r_val)
    else:
        r_ptr = 0

    def vcall_impl(em, a):
        em.calllog.append(('5335a0_vcall', 0x244, em.reg('ecx'), (em.arg32(0),)))
        return (r_ptr, None)

    this_obj = _rnd(c, 0x40)
    # Set up vtable with logging
    e.w32(this_obj, e.logging_vtable('5335a0_vt', 0x244 // 4 + 1, impl={0x244: vcall_impl}, argwords={0x244: 1}))

    return [this_obj, c.rng.getrandbits(32)]


def _gen_433420(c):
    # 0x433420: thiscall(a) - calls 0x431410(0x67a048, a)
    e = c.emu

    ret_val = c.rng.getrandbits(32)

    def hook_431410(em, r):
        em.calllog.append(('431410', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=ret_val, argbytes=8)

    e.hook(0x431410, hook_431410)

    return [_rnd(c, 0x100), c.rng.getrandbits(32)]


def _gen_448be0(c):
    # 0x448be0: thiscall(a) - calls 0x448a30(this, a) then 0x4e1b30(a)
    e = c.emu

    ret_val_1 = c.rng.getrandbits(32)
    ret_val_2 = c.rng.getrandbits(32)

    def hook_448a30(em, r):
        em.calllog.append(('448a30', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=ret_val_1, argbytes=4)

    def hook_4e1b30(em, r):
        em.calllog.append(('4e1b30', 0, em.reg('ecx'), ()))
        em.ret(eax=ret_val_2, argbytes=0)

    e.hook(0x448a30, hook_448a30)
    e.hook(0x4e1b30, hook_4e1b30)

    return [_rnd(c, 0x100), c.rng.getrandbits(32)]


def _gen_427120(c):
    # 0x427120: cdecl, ret=eax:edx - calls [0x676124] with &local (8 bytes)
    e = c.emu

    ret_val = c.rng.getrandbits(64)

    def hook_iat(em, r):
        local_ptr = em.arg32(0)
        em.calllog.append(('iat_676124', 0, None, (local_ptr,)))
        # Write the return value to the local buffer
        em.w32(local_ptr, ret_val & 0xffffffff)
        em.w32(local_ptr + 4, (ret_val >> 32) & 0xffffffff)
        em.ret(eax=None, argbytes=4)

    e.hook(0x676124, hook_iat)

    return []


S(0x65f1e0, 'GUESS FUN_0065f1e0 (unknown) stdcall', 'stdcall', None, ret=None, gen=_gen_f1e0,
  note='residue 6 batch 88; [p+0x24] |= 1; [p+0x40] = f')
S(0x5335a0, 'GUESS FUN_005335a0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_5335a0,
  note='residue 6 batch 88; r = vcall(this, 0x244, a); returns r ? *r : 0')
S(0x433420, 'GUESS FUN_00433420 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_433420,
  note='residue 6 batch 88; [this+0xf8] = a; returns 0x431410(0x67a048, a)')
S(0x448be0, 'GUESS FUN_00448be0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_448be0,
  note='residue 6 batch 88; 0x448a30(this, a); 0x4e1b30(a); returns 0')
S(0x427120, 'GUESS FUN_00427120 (unknown) cdecl', 'cdecl', None, ret='eax:edx', gen=_gen_427120,
  note='residue 6 batch 88; calls [0x676124] with &local (8 bytes)')

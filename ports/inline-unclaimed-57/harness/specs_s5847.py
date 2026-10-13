"""specs_s5847.py - 0x5d42d0 (FUN_005d42d0, ZFF bomb/fuse frame update). Thiscall, no args, plain ret.
Engine 0x70039c: frame counters +0x40/+0x44, sub-object +0x9b with slots 0x138, 0x58, 0x4c; sound +0x1a9f with slot 0x120.
Engine 0x70038c: object with slot 0xcc.
Members: +0x44 owner (slots 0x80 WriteMatrix out-args m[12] v[3], 0x128 pair id, 0x20 returns obj+4=name ptr, 0x210 one arg),
+0x48 visual (slots 0x7c WriteMatrix m v, 0x234 color, 0x28, 0x210), +0x5f object for 0x5ea840(float t);
+0x63 effect (slots 0x1bc(7 args) returns fx, 0x138 pair id dmg, 0x2c); +0x4e-0x67 word/dword/byte/float/object/sound-id fields.
Hooked: 0x5ea840 (thiscall, one float arg, ret 4); 0x4db3b0 (thiscall, no args, returns bone object).
Slot 0x80 writes random 0x30-byte matrix and 0xc-byte vector to out-args; slot 0x88 writes random key; slot 0x128 receives [name, id] pair (8 bytes)."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a




def _d5d42d0(c):
    import struct
    e = c.emu
    rnd = c.rng
    self_obj = _rnd(c, 0x100)

    def rel(p):
        return ('self', p - self_obj) if self_obj <= p < self_obj + 0x100 else ('other', p)

    def read_floats(ptr, n):
        """Read n floats from memory and return as tuple of float bits."""
        return tuple(e.r32(ptr + i * 4) for i in range(n))

    # Hooked external callees
    def h5ea840(em, r):
        t = F(em.argf(0))
        em.calllog.append(('5ea840', t, None, ()))
        em.ret(eax=0, argbytes=4)

    def h4db3b0(em, r):
        em.calllog.append(('4db3b0', None, None, ()))
        # Return a bone object
        em.ret(eax=bone_obj, argbytes=0)

    # Virtual table slots
    def h80(em, r):
        # Slot 0x80: WriteMatrix(m[12], v[3])
        m_ptr = em.arg32(0)
        v_ptr = em.arg32(1)
        # Write random matrix and vector
        m_data = b''.join(rnd.getrandbits(32).to_bytes(4, 'little') for _ in range(12))
        v_data = b''.join(rnd.getrandbits(32).to_bytes(4, 'little') for _ in range(3))
        em.wbytes(m_ptr, m_data)
        em.wbytes(v_ptr, v_data)
        em.calllog.append(('80', read_floats(m_ptr, 12), read_floats(v_ptr, 3), ()))
        em.ret(eax=0, argbytes=8)

    def h7c(em, r):
        # Slot 0x7c: SetMatrix(m[12], v[3])
        m_ptr = em.arg32(0)
        v_ptr = em.arg32(1)
        em.calllog.append(('7c', read_floats(m_ptr, 12), read_floats(v_ptr, 3), ()))
        em.ret(eax=0, argbytes=8)

    def h128(em, r):
        # Slot 0x128: (id, pair[2], 0)
        id_val = em.arg32(0)
        pair_ptr = em.arg32(1)
        pair = (em.r32(pair_ptr), em.r32(pair_ptr + 4))
        em.calllog.append(('128', id_val, pair, ()))
        em.ret(eax=0, argbytes=12)

    def h20(em, r):
        # Slot 0x20: returns object with name ptr at +4
        obj_ptr = _rnd(c, 0x40)
        em.w32(obj_ptr + 4, rnd.choice([0x67c8e8, 0, rnd.getrandbits(32)]))  # 0x67c8e8 = "<NONAME>"
        em.calllog.append(('20', rel(obj_ptr), None, ()))
        em.ret(eax=obj_ptr, argbytes=0)

    def h210(em, r):
        # Slot 0x210: one argument
        arg = em.arg32(0)
        em.calllog.append(('210', arg, None, ()))
        em.ret(eax=0, argbytes=4)

    def h234(em, r):
        # Slot 0x234: color (one dword argument)
        col = em.arg32(0)
        em.calllog.append(('234', col, None, ()))
        em.ret(eax=0, argbytes=4)

    def h28(em, r):
        # Slot 0x28: no logged args
        em.calllog.append(('28', None, None, ()))
        em.ret(eax=0, argbytes=0)

    def h138(em, r):
        # Slot 0x138: (id, dmg, 0)
        id_val = em.arg32(0)
        dmg = em.arg32(1)
        em.calllog.append(('138', id_val, dmg, ()))
        em.ret(eax=0, argbytes=12)

    def h1bc(em, r):
        # Slot 0x1bc: (bone, m[12], v[3], 0, 0, 0, 0) returns fx object
        bone = em.arg32(0)
        m_ptr = em.arg32(1)
        v_ptr = em.arg32(2)
        m_data = read_floats(m_ptr, 12)
        v_data = read_floats(v_ptr, 3)
        fx_ptr = _rnd(c, 0x100)
        em.calllog.append(('1bc', rel(bone), m_data, (v_data,)))
        em.ret(eax=fx_ptr, argbytes=28)

    def h2c(em, r):
        # Slot 0x2c: no args
        em.calllog.append(('2c', None, None, ()))
        em.ret(eax=0, argbytes=0)

    def h94(em, r):
        # Slot 0x94 on bone: (m[12], v[3])
        m_ptr = em.arg32(0)
        v_ptr = em.arg32(1)
        m_data = read_floats(m_ptr, 12)
        v_data = read_floats(v_ptr, 3)
        em.calllog.append(('94', m_data, v_data, ()))
        em.ret(eax=0, argbytes=8)

    def h120(em, r):
        # Slot 0x120: (id, 4u)
        id_val = em.arg32(0)
        four = em.arg32(1)
        em.calllog.append(('120', id_val, four, ()))
        em.ret(eax=0, argbytes=8)

    def h68(em, r):
        # Slot 0x68 on self: (0x10u, 0u)
        arg1 = em.arg32(0)
        arg2 = em.arg32(1)
        em.calllog.append(('68', arg1, arg2, ()))
        em.ret(eax=0, argbytes=8)

    def h88(em, r):
        # Slot 0x88 on table: (string_addr, &key) writes random key
        key_ptr = em.arg32(1)
        key_val = rnd.getrandbits(32)
        em.w32(key_ptr, key_val)
        em.calllog.append(('88', key_val, None, ()))
        em.ret(eax=0, argbytes=8)

    def hcc(em, r):
        # Slot 0xcc on engine2: (key) returns dmg value
        key = em.arg32(0)
        dmg = rnd.getrandbits(32)
        em.calllog.append(('cc', key, dmg, ()))
        em.ret(eax=dmg, argbytes=4)

    def h4c(em, r):
        # Slot 0x4c: (id)
        id_val = em.arg32(0)
        ret_val = rnd.getrandbits(32)
        em.calllog.append(('4c', id_val, ret_val, ()))
        em.ret(eax=ret_val, argbytes=4)

    def h58(em, r):
        # Slot 0x58: (id) returns obj
        id_val = em.arg32(0)
        obj = _rnd(c, 0x100)
        em.calllog.append(('58', id_val, None, ()))
        em.ret(eax=obj, argbytes=4)

    # Set up hooked callees
    e.hook(0x5ea840, h5ea840)
    bone_obj = _rnd(c, 0x100)
    e.hook(0x4db3b0, h4db3b0)

    # Create owner object with vtable
    owner = _rnd(c, 0x200)
    vt_owner = e.fake_vtable('d5d42d0_owner', 600, {
        0x20: h20, 0x80: h80, 0x128: h128, 0x210: h210
    })
    e.w32(owner, vt_owner)
    owner_sub = _rnd(c, 0x100)  # object for 0x4db3b0's ecx
    e.w32(owner + 8, owner_sub)

    # Create visual object with vtable
    visual = _rnd(c, 0x200)
    vt_visual = e.fake_vtable('d5d42d0_visual', 600, {
        0x28: h28, 0x7c: h7c, 0x234: h234, 0x210: h210
    })
    e.w32(visual, vt_visual)

    # Create effect object with vtable
    effect = _rnd(c, 0x200)
    vt_effect = e.fake_vtable('d5d42d0_effect', 600, {
        0x1bc: h1bc, 0x138: h138, 0x2c: h2c
    })
    e.w32(effect, vt_effect)

    # Bone object vtable
    vt_bone = e.fake_vtable('d5d42d0_bone', 600, {0x94: h94})
    e.w32(bone_obj, vt_bone)

    def h138_sub(em, r):
        # Slot 0x138 on sub: no args, returns table object
        tbl = _rnd(c, 0x100)
        em.calllog.append(('sub138', None, None, ()))
        em.ret(eax=tbl, argbytes=0)

    # Sub-object vtable (for engine +0x9b)
    vt_sub = e.fake_vtable('d5d42d0_sub', 600, {
        0x138: h138_sub,
        0x4c: h4c,
        0x58: h58
    })
    sub = _rnd(c, 0x200)
    e.w32(sub, vt_sub)

    # Sound object vtable
    vt_sound = e.fake_vtable('d5d42d0_sound', 600, {0x120: h120})
    sound = _rnd(c, 0x100)
    e.w32(sound, vt_sound)

    # Table object vtable
    vt_table = e.fake_vtable('d5d42d0_table', 600, {0x88: h88})
    table = _rnd(c, 0x100)
    e.w32(table, vt_table)

    # Engine2 object vtable
    vt_eng2 = e.fake_vtable('d5d42d0_eng2', 600, {0xcc: hcc})
    eng2 = _rnd(c, 0x100)
    e.w32(eng2, vt_eng2)

    # Main engine object
    eng = _rnd(c, 0x2000)
    e.w32(eng + 0x40, rnd.getrandbits(32))
    e.w32(eng + 0x44, rnd.getrandbits(32))
    e.w32(eng + 0x9b, sub)
    e.w32(eng + 0x1a9f, sound if rnd.random() < 0.7 else 0)
    e.w32(0x70039c, eng)

    # Set up self object
    e.w32(self_obj, e.fake_vtable('d5d42d0_self', 600, {0x68: h68}))
    e.w32(self_obj + 0x44, owner)
    e.w32(self_obj + 0x48, visual if rnd.random() < 0.9 else 0)
    e.w32(self_obj + 0x4e, rnd.getrandbits(16))
    e.w32(self_obj + 0x50, rnd.getrandbits(16))
    e.w32(self_obj + 0x52, rnd.getrandbits(16))
    e.w32(self_obj + 0x54, rnd.getrandbits(16))
    e.w32(self_obj + 0x56, rnd.choice([0, rnd.getrandbits(32)]))
    e.wbytes(self_obj + 0x5a, bytes([rnd.getrandbits(8)]))
    timer_val = rnd.choice([0.0, 5.0, 9.99, 10.0, 10.01, 15.0])
    e.wbytes(self_obj + 0x5b, struct.pack('<f', timer_val))
    e.w32(self_obj + 0x5f, _rnd(c, 0x100))
    e.w32(self_obj + 0x63, effect if rnd.random() < 0.8 else 0)
    e.w32(self_obj + 0x67, rnd.getrandbits(32))

    # Set up engine2
    e.w32(0x70038c, eng2)

    return [self_obj]


S(0x5d42d0, 'ZFF bomb/fuse frame update thiscall', 'thiscall', None, ret=None, gen=_d5d42d0,
  note='residue 9; complex vtable methods, out-args logged; hooked 0x5ea840, 0x4db3b0; engines 0x70039c, 0x70038c')
